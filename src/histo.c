#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "LUT.h"
#include "histo.h"

void lireListe(int liste[], int taille){
	int i;
	for(i=0; i<taille; i++){
		printf("%d\n",liste[i]);
	}
}

void initialiserHisto(int *histogramme){
    int i;
    for (i=0; i<256; i++){
        histogramme[i]=0;
    };
};

int ecrireHisto(Image *image, int histogramme[] ){
    int compteur=0;
    while(image->data[compteur]!='\0'){
    	histogramme[image->data[compteur]]+=1;
    	compteur+=3;
    }
    return histogramme;
};

int rechercheMax(int liste[],int taille){
    int i; 
    int max = 0;
    for(i=0; i<taille; i++){
        if(max < liste[i]){
            max = liste[i];
        }
    }
    return max;
};

void visualiserHisto(Image *image, int histogramme[]){
    unsigned int hauteur = rechercheMax(histogramme, 256);
    float diviseur = hauteur / 256.0;
    hauteur = hauteur / diviseur;
    int c;
    for(c=0; c<256; c++){
    	histogramme[c]=histogramme[c]/diviseur;
    }
    unsigned int largeur = 256;
    newImage(image,largeur,hauteur);
    int i=0;
    int j=0;
    int retourLigne = 0;
    while(i<256){
    	for(j=0; j<histogramme[i];j++){
    		image->data[retourLigne + j]=255;
    		image->data[retourLigne + j+1]=255;
    		image->data[retourLigne + j+2]=255;
    	};
    	retourLigne+=hauteur*3;
    	i++;
    }
    saveImagePPM(image, "histo.ppm");
    freeImage(image);
}

void faireHistogramme(Image *image){
	int tabHistogramme[256];
	initialiserHisto(tabHistogramme);
	
	ecrireHisto(&image, tabHistogramme);
	visualiserHisto(image, tabHistogramme);
};