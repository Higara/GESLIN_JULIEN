#ifndef HISTO_H__
#define HISTO_H__

#include "LUT.h"
#include "image.h"

void lireListe(int liste[], int taille);
void initialiserHisto(int *histogramme);
int ecrireHisto(Image *image, int histogramme[] );
int rechercheMax(int liste[],int taille);
void visualiserHisto(Image *image, int histogramme[]);
void faireHistogramme(Image *image);

#endif