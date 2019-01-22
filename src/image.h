#ifndef IMAGE_H__
#define IMAGE_H__

#include "LUT.h"

/// \brief structure that contains an image
typedef struct Image{
  unsigned char *data; //Pixels
  unsigned int width;
  unsigned int height;
}Image;


/// \brief allocate the memory for a new image
/// \param image: pointer on the image.
/// \param width: width of the required the image.
/// \param height: height of the required the image.
/// \return EXIT_FAILURE in case of problem, else EXIT_SUCCESS.
int newImage(Image *image, unsigned int width, unsigned int height);

/// \brief release the image memory
/// \param image: pointer on the image.
void freeImage(Image *image);

/// \brief save an image with PPM (P6) file format.
/// \param image: pointer on the image to save.
/// \param filename: char array containing the filename of the image to be saved.
/// \return EXIT_FAILURE in case of problem, else EXIT_SUCCESS.
int saveImagePPM(Image *image, char *filename);

/// \brief load an image with PPM (P6) file format.
/// \param image: pointer on the image to load.
/// \param filename: char array containing the filename of the image to load.
/// \return EXIT_FAILURE in case of problem, else EXIT_SUCCESS.
int loadImagePPM(Image *image, char *filename);

/// \brief checks if extension is PPM or not
/// \param nomFichier: char array containing the filename of the image to load
/// \param extens: char array of the extension of the file
//void extension(char *filename, char extens[])

int getPixel(Image *image, int x, int y, int color);

void setPIxel(Image *image, int x, int y, int color);

void applyLUT(Image *image, LUT *lut);

int limitValue(int value);

#endif
