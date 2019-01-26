#ifndef IMAGE_H__
#define IMAGE_H__



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

/// \brief get the relative position of the pixel and the rgb color layer.
/// \param image: pointer on the image to load.
/// \param x: the x-axis position of the pixel.
/// \param y: the y-axis position of the pixel.
/// \param x: the integer relative to the rgb layer (0:red, 1:green, 2:blue)
/// \return the field data[pixel + color]
int getPixel(Image *image, int x, int y, int color);


/// \brief replaces the value of the pixel with a value given in argument
/// \param image: pointer on the image to load.
/// \param x: the x-axis position of the pixel.
/// \param y: the y-axis position of the pixel.
/// \param x: the integer relative to the rgb layer (0:red, 1:green, 2:blue)
/// \param value: the integer used to change the value of the pixel color layer 
void setPixel(Image *image, int x, int y, int color, int value);

// \brief forces the pixels values to stay in bound between 0 et 255
// \param value: any integer given to the function
int limitValue(int value);

void faireHistogramme(Image *image);


#endif
