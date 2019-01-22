#include <stdio.h>
#include <stdlib.h>

#include "image.h"



int newImage(Image *image, unsigned int width, unsigned int height)
{
  // memory allocation
  image->data = (unsigned char*) malloc(sizeof(unsigned char) * 3 * width * height);
  if(image->data == NULL){
    printf("newImage : error bad memory allocation.\n");
    return EXIT_FAILURE;
  }

  // update width and height
  image->width  = width;
  image->height = height;

  return EXIT_SUCCESS;
}



void freeImage(Image *image)
{
  if(image != NULL) {
    if(image->data != NULL)	{
	    free(image->data);
      image->data= NULL;
    }

    image->width  = 0;
    image->height = 0;
	}
}



int saveImagePPM(Image *image, char *filename)
{
  // open the file
  FILE *myfile;
  myfile = fopen(filename,"wt");

  // save the data
  if (myfile)
  {
    // generate the header
    char header[100]; // bad way to proceed, but still ok ...
    sprintf(header,"P6\n#M. Nozick is a so nice person\n%d %d\n255\n",image->width,image->height);
    fprintf(myfile,"%s",header);

    // write the data
    fwrite(image->data,sizeof(unsigned char),image->width*image->height*3,myfile);

    // close the file
    fclose(myfile);
  }
  else
  {
    printf("saveImagePPM : error opening file %s.\n",filename);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}



// void extension(char nomFichier[], char extens[])
// {
//   int i, depart;
   
//   for(i=0; nomFichier[i] != '.'; i++);
//   depart = i+1;
//   for(; nomFichier[i] != '\0'; i++)
//     extens[i-depart] = nomFichier[i];
// }



int getPixel(Image *image, int x, int y, int color){
  int pixel;
  pixel= y*(image->width)*3+x*3;
  return image->data[pixel+color];

}
  
void setPixel(Image *image, int x, int y, int color, int value){
  int pixel;
  pixel= y*(image->width)*3+x*3;
  image->data[pixel+color]= value;

}

void applyLUT(Image *image, LUT *lut){
  int x, y; 
  int red, green, blue;


  for (x=0; x<image->width; x++){
    for (y=0; y<image->height; y++){


    red = getPixel(image, x, y, 0);
    green = getPixel(image, x, y, 1);
    blue = getPixel(image, x, y, 2);

    setPixel(image,x,y,0, lut->lutr[red]);
    setPixel(image, x, y, 1, lut->lutg[green]);
    setPixel(image,x,y, 2, lut->lutb[blue]);

    }
  }

}



// reads only P6
int loadImagePPM(Image *image, char *filename)
{
  FILE *myFile = NULL;
  char chaine[255];
  unsigned int width,height;

  // open the file
  if (!(myFile = fopen(filename, "rt")))
    {
      printf("loadImagePPM : error opening file %s.\n",filename);
      return EXIT_FAILURE;
    }

  // read header
  fscanf(myFile,"%s\n",chaine);

  // read comments ...
  do{ 
    fgets(chaine,255,myFile);
  } while (chaine[0]=='#');
  
  // read width and height
  sscanf(chaine,"%d %d",&width,&height);
  printf("width:  %d\nheight: %d\n",width,height);

  // read the "255"
  fscanf(myFile,"%s\n",chaine);

  // memory allocation
  if(newImage(image,width,height) == EXIT_FAILURE){
    printf("loadImagePPM : memory allocation error\n");
    return EXIT_FAILURE;
  }

  // read the data
  fread(image->data, sizeof (unsigned char), width*height * 3, myFile);

  // close the file
  fclose(myFile);

  return EXIT_SUCCESS;
}
