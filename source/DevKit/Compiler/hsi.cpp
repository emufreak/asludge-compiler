#include <stdio.h>
#include <string.h>

#include <png.h>

#include "moreio.h"
#include "helpers.h"
#include "splitter.hpp"
#include "interface.h"
#include "messbox.h"
#include "tga.h"
#include "compilerinfo.h"

unsigned short int * backDropImage;
bool backdrop32;
unsigned char * backDrop32Image;
int VERT_RES, HORZ_RES;

bool initBackDropForCompiler (int x, int y) {
	fprintf(stderr, "Init Backdrop for Compiler ...\n");
	int a;

	HORZ_RES = x;
	VERT_RES = y;

	int size = HORZ_RES*VERT_RES;
	backDropImage = new unsigned short int [size];
	if (! backDropImage) return false;

	fprintf(stderr, "Init Backdrop Successful\n");
	return true;
}

int loadBackDropForCompiler (char * fileName, palCol thePalette[256]) {
	fprintf(stderr, "Loading Backdrop for Compiler ...\n");
	unsigned short int * toScreen;
	unsigned short int t1, t2;

	// Open the file
	FILE * fp = fopen (fileName, "rb");
	if (fp == NULL) {
		return false;
	}

	// Grab the header
	TGAHeader imageHeader;
	const char * errorBack;
	errorBack = readTGAHeader (imageHeader, fp, thePalette);
	if (errorBack) {
//		alert (errorBack);
		return false;
	}

	if (imageHeader.pixelDepth < 24) {

		initBackDropForCompiler (imageHeader.width, imageHeader.height);


		unsigned short (* readColFunction) (FILE *, int, int, int) =
			imageHeader.compressed ? readCompressedPixel : readAPixel;

		for (t2 = imageHeader.height; t2; t2 --) {
			int tmp = (imageHeader.imageDescriptor & 32) ? (imageHeader.height - t2) : (t2 - 1);
			toScreen = &backDropImage[tmp * imageHeader.width];
			
			
			backDropImage[(imageHeader.imageDescriptor & 32) ? (imageHeader.height - t2) : (t2 - 1)];
			for (t1 = 0; t1 < imageHeader.width; t1 ++) {
				
				int tmp = readColFunction (fp, imageHeader.pixelDepth, t1, t2);
				//fprintf(stderr, "%d,",tmp);
				* (toScreen ++) = tmp;
			}
		}
	} else {

	}

	/*for(int i=0; i<imageHeader.width*imageHeader.height;i++)
	{
		fprintf(stderr, "%d,", backDropImage[i]);
	}*/


	int i = ftell (fp);
	fclose (fp);
	return i;
}

int saveHSI (char * filename, palCol thePalette[]) {
	fprintf(stderr, "saving HSI ...\n");
	fprintf(stderr, "saving HSI %s ...\n", filename);

	FILE * writer = fopen (filename, "wb");
	int x, y, lookAhead;
	unsigned short int * fromHere;
	unsigned short int * lookPointer;

	if (! writer) return 0;
	put2bytes (HORZ_RES, writer);
	put2bytes (VERT_RES, writer);
	
	for(int i=0;i<32;i++) { //Todo: Diffferent Bitplane Numbers
		int color = (thePalette[i].r /16) << 8;
		color += (thePalette[i].g /16) << 4;
		color += (thePalette[i].b /16);
		put2bytes (color, writer);
	}

	unsigned int bitplanesize = HORZ_RES*VERT_RES/8;

	//5 Bitplanes + Mask
	unsigned char *planes = new unsigned char[bitplanesize*6];	

	for(int i=0;i<bitplanesize;i++) {

		//Init values
		planes[i] = 0;
		planes[bitplanesize+i] = 0;
		planes[2*bitplanesize+i] = 0;
		planes[3*bitplanesize+i] = 0;
		planes[4*bitplanesize+i] = 0;
		planes[5*bitplanesize+i] = 0;

		for(int i2=0;i2<8;i2++) {

		//Amiga Todo: Different Bitplane number
		unsigned int tmp = backDropImage[i*8+i2];
		
		unsigned int bpl1 = (tmp & 0b1) ? 0b10000000 : 0;
		unsigned int bpl2 = (tmp & 0b10) ? 0b10000000 : 0;
		unsigned int bpl3 = (tmp & 0b100) ? 0b10000000 : 0;
		unsigned int bpl4 = (tmp & 0b1000) ? 0b10000000 : 0;
		unsigned int bpl5 = (tmp & 0b10000) ? 0b10000000 : 0;	
		unsigned int bplmask = tmp ? 0b10000000 : 0;

		planes[i] |= bpl1 >> i2;
		planes[bitplanesize+i] |= bpl2 >> i2;
		planes[2*bitplanesize+i] |= bpl3 >> i2;
		planes[3*bitplanesize+i] |= bpl4 >> i2;
		planes[4*bitplanesize+i] |= bpl5 >> i2;
		planes[5*bitplanesize+i] |= bplmask >> i2;
		//fprintf(stderr, "%d\n",tmp);
		}		
	}

	fprintf(stderr, "Bitplanes written to buffer ...\n");

	/*for(int i=0;i<160;i++) {
		fprintf(stderr, "%02x",planes[i]);
	}*/

	fwrite(planes, sizeof(char), bitplanesize*6,writer);


	int i = ftell (writer);
	fclose (writer);
	delete planes;
	fprintf(stderr, "HSI Saved ...\n");
	return i;
}

int savePNG (char * filename, int w, int h, unsigned char * data) {
	FILE * fp = fopen (filename, "wb");
	if (! fp) return 0;

	png_structp png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fclose (fp);
		return false;
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr){
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		fclose (fp);
		return false;
	}

	png_init_io(png_ptr, fp);

	png_set_IHDR(png_ptr, info_ptr, w, h,
				 8, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	unsigned char * row_pointers[h];

	for (int i = 0; i < h; i++) {
		row_pointers[i] = data + 4*i*w;
	}

	png_set_rows(png_ptr, info_ptr, row_pointers);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	int i = ftell (fp);
	fclose (fp);
	return i;
}


bool convertTGA (char * filename) {

	palCol thePalette[256];

	fprintf(stderr, "Converting TGA ...\n");

	char * oldName = joinStrings (filename, "");
	filename[strlen (filename) - 3] = 's';
	filename[strlen (filename) - 2] = 'l';
	filename[strlen (filename) - 1] = getDither() ? '2' : 'x';
	int i, j;

	if (newerFile (oldName, filename)) {
		fprintf(stderr, "Running newer file ...\n");
		backdrop32 = false;
		setCompilerText (COMPILER_TXT_ITEM, "Compressing image");		
		i = loadBackDropForCompiler (oldName, thePalette);
		if (! i) return false;
		if (backdrop32) {
			j = savePNG (filename, HORZ_RES, VERT_RES, backDrop32Image);
			delete backDrop32Image;

			if (! j) return false;
		} else {
			fprintf(stderr, "No PNG ...\n");
			j = saveHSI (filename, thePalette);
			//for (int a = 0; a < VERT_RES; a ++) delete backDropImage;
			delete backDropImage;

			if (! j) return false;
		}
		setCompilerText (COMPILER_TXT_ITEM, "");
	}
	delete oldName;
	fprintf(stderr, "Finished Converting ...\n");
	return true;
}
