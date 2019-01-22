#include <stdio.h>
#include <stdlib.h>

#include "LUT.h"

void lutInit(LUT *lut){
	for (int i= 0; i<256; i++){
		lut->lutr[i]=i;
		lut->lutg[i]=i;
		lut->lutb[i]=i;
	}
}

void addLum(LUT *lut,int value){
	for(int i=0; i<256;i++){
		lut->lutr[i] = lut->lutr[i]+value;
		lut->lutg[i] = lut->lutg[i]+value;
		lut->lutb[i] = lut->lutb[i]+value;
	}
}

void dimLum(LUT *lut,int value){
	for(int i=0; i<256;i++){
		lut->lutr[i] = lut->lutr[i]-value;
		lut->lutg[i] = lut->lutg[i]-value;
		lut->lutb[i] = lut->lutb[i]-value;
	}
}