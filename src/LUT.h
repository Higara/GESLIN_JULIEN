#ifndef LUT_H__
#define LUT_H__
#include "image.h"



/// \brief structure that defines a LUT
typedef struct Lut{
  int lutr[256];
  int lutg[256];
  int lutb[256];
}Lut;


// function that initializes a lut
void lutInit(Lut *lut);

/// \brief merges all the luts onto a single lut (instructions read from command line)
/// \param image: pointer on the image to load
/// \param lut: pointer on the final lut
/// \param argv: pointer of pointer on the list of arguments entered in command line
/// \param size: length of the array of arguments entered in command line
/// \param begin: integer specified to describe where the reading of the arguments should begin
void mergeLut(Image *image, Lut *lut, char **argv, int size, int begin);

/// \brief apply the final lut to the image
/// \param image: pointer on the image to load
/// \param lut: pointer on the final lut
void applyLUT(Image *image, Lut *lut);

// [LUT] function that allows user to increase the luminosity of 
//the image from a certain amount
void addLum(Lut *lut,int value);

// [LUT] function that allows user to decrease the luminosity of
// the image from a certain amount
void dimLum(Lut *lut,int value);

// [LUT] function that allows user to invert the colors of the image
void invert(Lut *lut);

// [LUT] function that allows user to increase the contrast of
// the image from a certain amount
void addCon(Lut *lut, int value);

// [LUT] function that allows user to decrease the contrast of
// the image from a certain amount
void dimCon(Lut *lut, int value);


// function that calculates the average of the three RGB layers
// and sets this new value as the pixel value. THIS IS NOT CONSIDERED A LUT
void greySelection(Image *image);

// [LUT] function that applies a sepia effect to the picture.
void sepia(Lut *lut);




#endif
