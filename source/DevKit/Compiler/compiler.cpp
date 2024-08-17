/*
 *  Compiler.cpp
 *  Sludge Dev Kit
 *
 *  Created by Rikard Peterson on 2009-07-16.
 *  Copyright 2009 Hungry Software and contributors. All rights reserved.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


#include "compiler.hpp"
#include "allknown.h"
#include "checkused.h"
#include "dumpfiles.h"
#include "sludge_functions.h"
#include "linker.h"
#include "messbox.h"
#include "preproc.h"
#include "project.hpp"
#include "realproc.h"
#include "splitter.hpp"
#include "translation.h"
#include "moreio.h"
#include "helpers.h"
#include "settings.h"
#include "hsi.h"
#include "objtype.h"
#include "interface.h"
#include "compilerinfo.h"
#include "utf8.h"

enum { CSTEP_INIT,
	   CSTEP_PARSE,
	   CSTEP_COMPILEINIT,
	   CSTEP_COMPILE,
	   CSTEP_AFTERCOMPILE,
	   CSTEP_LINKSCRIPTS,
	   CSTEP_AFTERLINKSCRIPTS,
	   CSTEP_LINKOBJECTS,
	   CSTEP_AFTERLINKOBJECTS,
	   CSTEP_DUMPFILES,
	   CSTEP_DONE,
	   CSTEP_ERROR };

const char * stageName[] = {
	"Initialisation", "Parsing", "Precompile", "Compiling",
	"Prelink", "Linking scripts", "Linking objects", "Linking objects",
	"Converting resources", "Attaching resources", "Done", "Compiliation aborted!"
};

static int compileStep = CSTEP_INIT;
static stringArray * globalVarNames = NULL;

static FILE * projectFile;
stringArray * allSourceStrings = NULL;
static stringArray * allTheFunctionNamesTemp = NULL;
static compilationSpace globalSpace;

static FILE * tempIndex;
static FILE * tempData;
static unsigned long iSize;
static int tot;

extern stringArray * allFileHandles;
extern int numStringsFound;
extern int numFilesFound;
extern stringArray * functionNames;
extern stringArray * objectTypeNames;

extern stringArray * builtInFunc;
extern stringArray * typeDefFrom;
extern stringArray * allKnownFlags;

char * gameFile = NULL;

static int data1 = 0, numProcessed = 0;


void setCompileStep (int a, int totalBits)
{
	compileStep = a;
	data1 = 0;

	setCompilerText (COMPILER_TXT_ACTION, stageName[a]);

	if (a <= CSTEP_DONE)
	{
		setCompilerText (COMPILER_TXT_FILENAME, "");
		setCompilerText (COMPILER_TXT_ITEM, "");

		clearRect (CSTEP_DONE, P_TOP);
		percRect (a, P_TOP);
		clearRect (totalBits, P_BOTTOM);
	}
}


bool doSingleCompileStep (char **fileList, int *numFiles) {

	fprintf(stderr, "Doing Single Compile Step ...\n");

	switch (compileStep)
	{
		case CSTEP_INIT:
		numProcessed = 0;
		setGlobPointer (& globalVarNames);

		if (! (*numFiles)) {
			addComment (ERRORTYPE_PROJECTERROR, "No files in project!", NULL);
			return false;
		}

		addToStringArray (allSourceStrings, "");
		if (! u8_isvalid(settings.windowName)) {
			return addComment (ERRORTYPE_PROJECTERROR, "Invalid window name.", "(It is not UTF-8 encoded.)", NULL, 0);
		}			
		addToStringArray (allSourceStrings, settings.windowName);
		if (! u8_isvalid(settings.quitMessage)) {
			return addComment (ERRORTYPE_PROJECTERROR, "Invalid quit message.", "(It is not UTF-8 encoded.)", NULL, 0);
		}
		addToStringArray (allSourceStrings, settings.quitMessage);
		clearComments();
		setCompileStep (CSTEP_PARSE, *numFiles);
		setCompilerStats (0, 0, 0, 0, 0);
		break;

		case CSTEP_PARSE:
		{
			if (data1 >= *numFiles) {
				setCompileStep (CSTEP_COMPILEINIT, 1);
			} else {
				char * tx = fileList[data1];
				fixPath(tx, true);
				setCompilerText (COMPILER_TXT_FILENAME, tx);
				percRect (data1, P_BOTTOM);

				char * compareMe = tx + (strlen (tx) - 4);
				char * lowExt = compareMe;
				while (*lowExt) {
					*lowExt = tolower (*lowExt);
					lowExt ++;
				}
				if (strcmp (compareMe, ".sld") == 0) {
					doDefines (tx, allSourceStrings, allFileHandles);
				} else if (strcmp (compareMe, ".slu") == 0) {
					if (! preProcess (tx, numProcessed ++, allSourceStrings, allFileHandles))
						return false;
				} else if (strcmp (compareMe, ".tra") == 0) {
					registerTranslationFile (tx);
				} else {
					return addComment (ERRORTYPE_PROJECTERROR, "What on Earth is this file doing in a project?", tx, NULL, 0);
				}
			}
			data1++;
		}
		break;

		case CSTEP_COMPILEINIT:
		numStringsFound = countElements (allSourceStrings);
		numFilesFound = countElements (allFileHandles);
		setCompileStep (CSTEP_COMPILE, numProcessed);
		if (! startFunction (protoFunction ("_globalInitFunction", ""), 0, globalSpace, "_globalInitFunction", true, false, "-")){
			addComment (ERRORTYPE_INTERNALERROR, "Couldn't create global variable initialisation code segment", NULL);
			return false;
		}
		break;

		case CSTEP_COMPILE:
		if (data1 >= numProcessed)
		{
			setCompileStep (CSTEP_AFTERCOMPILE, 1);
			break;
		}

		percRect (data1, P_BOTTOM);
		if (! realWork (data1, globalVarNames, globalSpace))
			return false;
		data1 ++;
		break;

		case CSTEP_AFTERCOMPILE:

		{

            outputHalfCode (globalSpace, SLU_LOAD_GLOBAL, "init");
            outputDoneCode (globalSpace, SLU_CALLIT, 0);
            finishFunctionNew (globalSpace, NULL);

            setCompilerStats (countElements (functionNames) - 1,
                countElements (objectTypeNames),
                countElements (allFileHandles),
                countElements (globalVarNames),
                countElements (allSourceStrings));

            checkUsedInit (CHECKUSED_FUNCTIONS, countElements (functionNames));
            setUsed(CHECKUSED_FUNCTIONS, 0);

            checkUsedInit (CHECKUSED_GLOBALS, countElements (globalVarNames));

            stringArray * silenceChecker = allFileHandles;
            while (silenceChecker) {
                if (audioFile (silenceChecker -> string)) silent = false;
                silenceChecker = silenceChecker -> next;
            }
            projectFile = openFinalFile (".sl~", "wb");
            if (! projectFile) {
                addComment (ERRORTYPE_SYSTEMERROR, "Can't open output file for writing", NULL);
                return false;
            }

            FILE * textFile = (programSettings.compilerWriteStrings) ? openFinalFile (" text.txt", "wt") : NULL;

            writeFinalData (projectFile);

            unsigned char customIconLogo = 0;

            if (settings.customIcon && settings.customIcon[0])
                customIconLogo +=1;

            if (settings.customLogo && settings.customLogo[0])
                customIconLogo +=2;

            fputc (customIconLogo, projectFile);

            // ADD ICON ------------------------------------
            if (customIconLogo & 1) {
                setCompilerText (COMPILER_TXT_ACTION, "Adding custom icon");
                setCompilerText (COMPILER_TXT_FILENAME, settings.customIcon);
                setCompilerText (COMPILER_TXT_ITEM, "");
                char * iconFile = joinStrings (settings.customIcon, "");
                if (getFileType (iconFile) == FILETYPE_TGA) {
                    convertTGA (iconFile);
                    if (! dumpFileInto (projectFile, iconFile)) {
                        fclose (projectFile);
                        return addComment (ERRORTYPE_PROJECTERROR, "Error adding custom icon (file not found or not a valid TGA or PNG file)", settings.customIcon, NULL, 0);
                    }
                } else {
                    if (! dumpFileInto (projectFile, iconFile)) {
                        fclose (projectFile);
                        return addComment (ERRORTYPE_PROJECTERROR, "Error adding custom icon", settings.customIcon, NULL, 0);
                    }
                }
                delete iconFile;
            }
            // ADD LOGO ------------------------------------
            if (customIconLogo & 2) {
                setCompilerText (COMPILER_TXT_ACTION, "Adding custom logo");
                setCompilerText (COMPILER_TXT_FILENAME, settings.customLogo);
                setCompilerText (COMPILER_TXT_ITEM, "");
                char * logoFile = joinStrings (settings.customLogo, "");
                if (getFileType (logoFile) == FILETYPE_TGA) {
                    convertTGA (logoFile);
                    if (! dumpFileInto (projectFile, logoFile)) {
                        fclose (projectFile);
                        return addComment (ERRORTYPE_PROJECTERROR, "Error adding custom logo (file not found or not a valid TGA or PNG file)", settings.customLogo, NULL, 0);
                    }
                } else {
                    if (! dumpFileInto (projectFile, logoFile)) {
                        fclose (projectFile);
                        return addComment (ERRORTYPE_PROJECTERROR, "Error adding custom logo", settings.customLogo, NULL, 0);
                    }
                }
                delete logoFile;
            }
            //----------------------------------------------

            put2bytes (countElements (globalVarNames), projectFile);

            if (! saveStrings (projectFile, textFile, allSourceStrings)) {
                fclose (projectFile);
                addComment (ERRORTYPE_SYSTEMERROR, "Can't save string bank(s)", NULL);
                return false;
            }

            if (! gotoTempDirectory ()) {
                fclose (projectFile);
                return false;
            }
            tempIndex = fopen ("SLUDGE1.tmp", "wb");
            tempData = fopen ("SLUDGE2.tmp", "wb");

            allTheFunctionNamesTemp = functionNames;
            iSize = countElements (functionNames) * 4 + ftell (projectFile) + 4;

            setCompileStep (CSTEP_LINKSCRIPTS, countElements(functionNames));
            break;

		}

		case CSTEP_LINKSCRIPTS:
		if (data1 < countElements(functionNames)) {
			percRect (data1, P_BOTTOM);
			if (! runLinker (tempData, tempIndex, data1, globalVarNames, iSize, allSourceStrings)) {
				fclose (projectFile);
				return false;
			}
			allTheFunctionNamesTemp = allTheFunctionNamesTemp -> next;
			data1 ++;
		} else {
			setCompileStep (CSTEP_AFTERLINKSCRIPTS, 1);
		}
		break;

		case CSTEP_AFTERLINKSCRIPTS:
		put4bytes (ftell (tempIndex) + ftell (tempData), projectFile);
		fclose (tempIndex);
		fclose (tempData);
		dumpFileInto (projectFile, "SLUDGE1.tmp");
		dumpFileInto (projectFile, "SLUDGE2.tmp");
		setCompileStep (CSTEP_LINKOBJECTS, tot);
		tot = countElements (objectTypeNames);

		tempIndex = fopen ("SLUDGE1.tmp", "wb");
		tempData = fopen ("SLUDGE2.tmp", "wb");

		iSize = tot * 4 + ftell (projectFile) + 4;
		setCompileStep (CSTEP_LINKOBJECTS, tot);

		break;

		case CSTEP_LINKOBJECTS:
		if (data1 < tot) {
			percRect (data1, P_BOTTOM);
			if (! linkObjectFile (tempData, tempIndex, data1, iSize)) {
				fclose (projectFile);
				return false;
			}
			data1 ++;
		} else {
			setCompileStep (CSTEP_AFTERLINKOBJECTS, 0);
		}
		break;

		case CSTEP_AFTERLINKOBJECTS:
		put4bytes (ftell (tempIndex) + ftell (tempData), projectFile);
		fclose (tempIndex);
		fclose (tempData);
		dumpFileInto (projectFile, "SLUDGE1.tmp");
		dumpFileInto (projectFile, "SLUDGE2.tmp");
		unlink ("SLUDGE1.tmp");
		unlink ("SLUDGE2.tmp");

		extern stringArray * globalVarFileOrigins;
		extern stringArray * functionFiles;

		warnAboutUnused (CHECKUSED_FUNCTIONS, functionNames, "Function ", functionFiles);
		warnAboutUnused (CHECKUSED_GLOBALS, globalVarNames, "Global variable ", globalVarFileOrigins);

		setCompileStep (CSTEP_DUMPFILES, 1);
		break;

		case CSTEP_DUMPFILES:
		if (! dumpFiles (projectFile, allFileHandles)) {
			fclose (projectFile);
			return false;
		}
		fclose (projectFile);
		gotoSourceDirectory ();
		char * fromName = joinStrings (settings.finalFile, ".sl~");
		if (gameFile) deleteString (gameFile);
		gameFile = joinStrings (settings.finalFile, settings.forceSilent ? " (silent).slg" : ".slg");
		unlink (gameFile);

		if (rename (fromName, gameFile))
		{
			addComment (ERRORTYPE_SYSTEMERROR, "Couldn't rename the compiled game file... it's been left with the name", fromName, NULL, 0);
		}
		deleteString(fromName);
		setCompileStep (CSTEP_DONE, 0);
		break;
	}

	return true;
}

int compileEverything (char * project, char **fileList, int *numFiles, void (*infoReceiver)(compilerInfo *)) {
	
	fprintf(stderr, "Compiling Everything ...\n");

	int success = true;
	setInfoReceiver(infoReceiver);

	clearTranslations ();
	if (! getSourceDirFromName (project)) {
		setCompilerText (COMPILER_TXT_ACTION, "Error initialising!");
		setCompilerText (COMPILER_TXT_FILENAME, "Could not find the folder for the source files.");
		return false;
	}

	initBuiltInFunc ();

	compileStep = CSTEP_INIT;
	while (compileStep < CSTEP_DONE) {
		if (! doSingleCompileStep (fileList, numFiles))
		{
			setCompileStep (CSTEP_ERROR, 1);
			gotoSourceDirectory ();
			char * killName = joinStrings (settings.finalFile, ".sl~");
			unlink (killName);
			delete killName;
			success = false;
		}
	}

	destroyAll (functionNames);
	destroyAll (objectTypeNames);
	destroyAll (globalVarNames);
	destroyAll (builtInFunc);
	destroyAll (typeDefFrom);
	destroyAll (allKnownFlags);
	destroyAll (allSourceStrings);
	destroyAll (allFileHandles);

	killTempDir();
	setFinished(success);
	return success;
}
