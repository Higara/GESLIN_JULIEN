#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "LUT.h"


void lutInit(Lut *lut){
	for (int i= 0; i<256; i++){
		lut->lutr[i]=i;
		lut->lutg[i]=i;
		lut->lutb[i]=i;
	}
}

void addLum(Lut *lut,int value){
	for(int i=0; i<256;i++){
		lut->lutr[i] = lut->lutr[i]+value;
		lut->lutg[i] = lut->lutg[i]+value;
		lut->lutb[i] = lut->lutb[i]+value;
	}
}

void dimLum(Lut *lut,int value){
	for(int i=0; i<256;i++){
		lut->lutr[i] = lut->lutr[i]-value;
		lut->lutg[i] = lut->lutg[i]-value;
		lut->lutb[i] = lut->lutb[i]-value;
	}
}

void invert(Lut *lut){
	for(int i=0; i<256;i++){
		lut->lutr[i] = 255-lut->lutr[i];
		lut->lutg[i] = 255-lut->lutg[i];
		lut->lutb[i] = 255-lut->lutb[i];
	}
}


void addCon(Lut *lut, int value){
	for(int i=0; i<256; i++){
		lut->lutr[i] = lut->lutr[i]+(value* sin(lut->lutr[i]*((2*M_PI)/255)-M_PI));
		lut->lutg[i] = lut->lutg[i]+(value* sin(lut->lutg[i]*((2*M_PI)/255)-M_PI));
		lut->lutb[i] = lut->lutb[i]+(value* sin(lut->lutb[i]*((2*M_PI)/255)-M_PI));
	}
}


void dimCon(Lut *lut, int value){
	for(int i=0; i<256; i++){
		int red = lut->lutr[i]-(value* sin(lut->lutr[i]*((2*M_PI)/255)-M_PI));
		int green = lut->lutg[i]-(value* sin(lut->lutg[i]*((2*M_PI)/255)-M_PI));
		int blue = lut->lutb[i]-(value* sin(lut->lutb[i]*((2*M_PI)/255)-M_PI));

		if((lut->lutr[i]<128 && red>128) || (lut->lutr[i]>128 && red<128)){
			red=128;
		}

		if((lut->lutb[i]<128 && green>128) || (lut->lutg[i]>128 && green<128)){
			green=128;
		}

		if((lut->lutb[i]<128 && blue>128) || (lut->lutb[i]>128 && blue<128)){
			blue=128;
		}
		lut->lutr[i] = red;
		lut->lutg[i] = green;
		lut->lutb[i] = blue;

	}
}

void greySelection(Image *image){
	for (int x=0; x<image->width; x++){
    	for(int y=0; y<image->height; y++){
      		int moyenne;

      		int redLayer= getPixel(image,x,y,0);
      		int greenLayer= getPixel(image,x,y,1);
      		int blueLayer= getPixel(image,x,y,2);

      		moyenne=(int)((redLayer + greenLayer + blueLayer)/3);

      		setPixel(image,x,y,0, moyenne);
      		setPixel(image,x,y,1, moyenne);
      		setPixel(image,x,y,2, moyenne);

    	}	
	}

}



void sepia(Lut *lut){
	for(int i=0; i<256; i++){
		int red = (lut->lutr[i] * .393) + (lut->lutg[i] *.769) + (lut->lutb[i] * .189);
		int green = (lut->lutr[i] * .349) + (lut->lutg[i] *.686) + (lut->lutb[i] * .168);
		int blue = (lut->lutr[i] * .272) + (lut->lutg[i] *.534) + (lut->lutb[i] * .131);

		lut->lutr[i] = red;
		lut->lutg[i] = green;
		lut->lutb[i] = blue;

	}
}

