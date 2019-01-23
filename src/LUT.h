#ifndef LUT_H__
#define LUT_H__



/// \brief structure that defines a LUT
typedef struct Lut{
  int lutr[256];
  int lutg[256];
  int lutb[256];
}Lut;

void lutInit(Lut *lut);


void addLum(Lut *lut,int value);

void dimLum(Lut *lut,int value);

void invert(Lut *lut);






#endif
