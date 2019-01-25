#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "LUT.h"

int main(int argc, char **argv)
{
    // create an image
    Image image;

    //declare filename from command line
    char finalname[50]="pics/";
    char source[50]="pics/";
    strcat(source,argv[1]);

    //test if file is PPM or not
    // char extens[10] = "";
    // extension("exemple.MPEG", extens);
    // if(extension)

    // load a ppm file
    if(loadImagePPM(&image,source) != EXIT_SUCCESS){
        return EXIT_FAILURE;
    }

    // modify the image (red pixel in the center)
    // unsigned int pixel = (image.width*(image.height) + (image.width))*3;
    // printf("%d\n",pixel);
    // image.data[pixel + 0] = 0; // Red
    // image.data[pixel + 1] = 255; // Green
    // image.data[pixel + 2] = 0; // Blue

    Lut lut;
    lutInit(&lut);
    mergeLut(&image,&lut, argv, argc-1,1); // SIZE A MODIFIER A 2 QUAND IMAGE SERA SPECIFIEE EN LIGNE DE COMMANDE
    applyLUT(&image,&lut);                 // PENSER A MODIFIER ARGC-1 EN ARGC-2


    // save the image (if the directory "images" already exists)
    strcat(finalname, argv[argc-1]);
    saveImagePPM(&image, finalname);

    // free the image memory
    freeImage(&image);



    return 0;
}


