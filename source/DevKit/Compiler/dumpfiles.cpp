#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "splitter.hpp"
#include "interface.h"
#include "settings.h"
#include "helpers.h"
#include "hsi.h"
#include "messbox.h"
#include "moreio.h"
#include "floor.h"
#include "translation.h"
#include "dumpfiles.h"
#include "compilerinfo.h"

bool dumpFileInto (FILE * writer, const char * thisFile) {
	int a;
	FILE * reader = fopen (thisFile, "rb");
	char buf[256];

	if (! reader) return false;
	while (true) {
		a = fread(buf, 1, 256, reader);
		if (! a) break;
		fwrite (buf, 1, a, writer);
	}
	fclose (reader);
	return true;
}

int getFileType (const char * filename) {
	int reply = FILETYPE_UNKNOWN;

	if (strlen (filename) >= 4) {
		char * compareMe = copyString(filename + (strlen (filename) - 4));
		for (int ii = 0; ii < 4; ii ++)
		{
			if (compareMe[ii] >= 'A' && compareMe[ii] <= 'Z')
				compareMe[ii] += 'a' - 'A';
		}

		if (strcmp (compareMe, ".tga") == 0) {
			reply = FILETYPE_TGA;
		} else if (strcmp (compareMe, ".flo") == 0) {
			reply = FILETYPE_FLOOR;
		} else if ( strcmp (compareMe, ".mid") == 0 ||
					strcmp (compareMe, ".rmi") == 0) {
			reply = FILETYPE_MIDI;
		} else if ( strcmp (compareMe, ".wav") == 0 ||
//					strcmp (compareMe, ".mp3") == 0 ||
					strcmp (compareMe, ".ogg") == 0 ||
				   // WebM is counted as audio so sound will be initialized for it
				   strcmp (compareMe, "webm") == 0 ||
					strcmp (compareMe + 1, ".xm") == 0 ||
					strcmp (compareMe + 1, ".it") == 0 ||
					strcmp (compareMe, ".s3m") == 0 ||
					strcmp (compareMe, ".mod") == 0
//					strcmp (compareMe, ".mo3") == 0 ||
//					strcmp (compareMe, ".avi") == 0) {
				   ) {
			reply = FILETYPE_AUDIO;
		} else if (	strcmp (compareMe, ".duc") == 0 ||
					strcmp (compareMe, ".zbu") == 0 ||
					strcmp (compareMe, ".png") == 0) {
			reply = FILETYPE_RAW;
		}
		delete compareMe;
	}

	return reply;
}

bool dumpFiles (FILE * mainFile, stringArray * & theSA) {

	if (! theSA) return true;

	// Display first...

	setCompilerText (COMPILER_TXT_ACTION, "Attaching sprites, images and audio files");
	setCompilerText (COMPILER_TXT_ITEM, "");

	int numFiles = countElements (theSA);

	clearRect (numFiles, P_BOTTOM);

	// Now the hard work
	unsigned long remainingIndexSize[numFiles];
	unsigned long currentRemainingIndex;
	unsigned long filesize;

	currentRemainingIndex = remainingIndexSize[0] = numFiles * 4 - 4;

	long lookup = ftell(mainFile);
	fseek(mainFile, lookup+currentRemainingIndex+4, SEEK_SET);

	int i = 0;

	FILE * inFile;
	gotoSourceDirectory ();

	char buf[0xFFFF];

	bool killAfterAdd;
	while (theSA) {
		setCompilerText (COMPILER_TXT_FILENAME, theSA -> string);

		killAfterAdd = false;
		if (! theSA -> string[0]) {
			// Nothing - used in forceSilent mode to replace audio
			put4bytes (0, mainFile);

			// Save the distance from here to the data in the index...
			remainingIndexSize[i] = currentRemainingIndex;
		} else {
			switch (getFileType (theSA->string)) {
				case FILETYPE_TGA:
				convertTGA (theSA -> string);
				killAfterAdd = programSettings.compilerKillImages;
				break;

				case FILETYPE_FLOOR:
				convertFloor (theSA -> string);
				killAfterAdd = true;
				break;

				case FILETYPE_MIDI:
				addComment (ERRORTYPE_PROJECTWARNING, "The current version of the SLUDGE engine cannot play MIDI files such as", theSA->string, NULL, 0);
				break;

				case FILETYPE_UNKNOWN:
				return addComment (ERRORTYPE_PROJECTERROR, "Tried to include a file which is not supported by SLUDGE.\n\nSupported music types: .XM, .MOD, .S3M, .IT\nSupported sampled sound types: .WAV, .OGG\nSupported graphic types: .TGA, .PNG\nSupported movie format: .WebM\nSLUDGE-specific types: .FLO, .ZBU, .ADUC\n\nThe file you tried to include was:", theSA -> string, NULL, 0);
			}

			inFile = fopen (theSA -> string, "rb");
			if (inFile == NULL) {
				return addComment (ERRORTYPE_PROJECTERROR, "Can't read resource file", theSA -> string, NULL, 0);
			}
			fseek (inFile, 0, 2);
			filesize = ftell (inFile);
			fseek (inFile, 0, 0);

			// Save the size at the start of the data...
			put4bytes (filesize, mainFile);

			// Save the distance from here to the data in the index...
			remainingIndexSize[i] = currentRemainingIndex;

			currentRemainingIndex += filesize;

			int a = 0;
			while (filesize -= a) {
				a = fread(buf, 1, 0xFFFF, inFile);
				if (! a) break;
				fwrite (buf, 1, a, mainFile);
			}

			fclose (inFile);
			if (killAfterAdd) unlink (theSA -> string);
		}
		destroyFirst (theSA);
		percRect (++ i, P_BOTTOM);
	}
	long filePos = ftell(mainFile);

	setCompilerText (COMPILER_TXT_ACTION, "Adding look-up table");
	setCompilerText (COMPILER_TXT_FILENAME, "");
	percRect (++ i, P_BOTTOM);

	fseek(mainFile, lookup, SEEK_SET);
	for (i=0;i<numFiles;i++) {
		put4bytes (remainingIndexSize[i], mainFile);
	}
	fseek(mainFile, filePos, SEEK_SET);

	return true;
}

bool saveStrings (FILE * mainFile, FILE * textFile, stringArray * theSA) {
	stringArray * wholeStringThing = theSA;

	FILE * projectFile, * indexFile;
	int indexSize = countElements (theSA) * 4 + ftell (mainFile) + 4;

	if (! gotoTempDirectory ()) return false;
	projectFile = fopen ("txtdata.tmp", "wb");
	indexFile = fopen ("txtindex.tmp", "wb");
	if (! (projectFile && indexFile)) return false;

	while (theSA) {
		put4bytes ((ftell (projectFile) + indexSize), indexFile);
		writeString (theSA -> string, projectFile);
		if (textFile) fprintf (textFile, "%s\n", theSA -> string);
		theSA = theSA -> next;
	}

	put4bytes (ftell (projectFile) + indexSize, mainFile);

	fclose (projectFile);
	fclose (indexFile);
	if (textFile) fclose (textFile);

	if (! gotoTempDirectory ()) return false;
	if (dumpFileInto (mainFile, "txtindex.tmp") && dumpFileInto (mainFile, "txtdata.tmp")) {
		unlink ("txtindex.tmp");
		unlink ("txtdata.tmp");
		return addAllTranslationData (wholeStringThing, mainFile);
	} else {
		return false;
	}
}
