#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "LUT.h"
#include "histo.h"

int main(int argc, char **argv)
{
    // create an image
    Image image;

    //declare filename from command line
    char finalname[50]="images/";
    char source[50]="images/";
    strcat(source,argv[1]);

    // load a ppm file
    if(loadImagePPM(&image,source) != EXIT_SUCCESS){
        return EXIT_FAILURE;
    }

    Lut lut;
    lutInit(&lut);
    mergeLut(&image,&lut, argv, argc-2,2); // SIZE A MODIFIER A 2 QUAND IMAGE SERA SPECIFIEE EN LIGNE DE COMMANDE
    applyLUT(&image,&lut);                 // PENSER A MODIFIER ARGC-1 EN ARGC-2


    // save the image (if the directory "images" already exists)
    strcat(finalname, argv[argc-1]);
    saveImagePPM(&image, finalname);

    // free the image memory
    freeImage(&image);

    return 0;
}


