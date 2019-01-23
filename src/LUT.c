#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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



