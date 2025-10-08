#ifndef FILTERS_H
#define FILTERS_H

#include "Image_Class.h"
using namespace std;

Image Grayscale_Filter1(Image img);


Image Black_And_White_Filter2(Image img);


Image invertImage3(Image img);


Image mergeImages4(Image img1, Image img2);


Image flip_Horizontal5(Image& image);

Image flip_Vertical5(Image& image);

Image rotateImage6(Image img, int angle);


Image adjustBrightness7(Image img, float factor);


Image cropImage8(Image& img, int x, int y, int newWidth, int newHeight);

Image addFrame9(Image& img, int thickness, unsigned char r, unsigned char g, unsigned char b);


Image detectEdges10(Image img);

Image resizeImage11(Image& img, float scale);


Image blurImage12(Image img, int intensity);

Image Wano15(Image toedit);

#endif