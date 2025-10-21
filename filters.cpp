



#include <iostream>
#include "Filters.h"
using namespace std;
// Filter 1: Grayscale Conversion
Image Grayscale_Filter1(Image img) {
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            unsigned int ave = 0;
            for (int k = 0; k < img.channels; k++) {
                ave += img(i, j, k);

            }
            ave = ave / 3;
            for (int k = 0; k < 3; k++) {
                img(i, j, k) = ave;
            }
        }
    }
    return img;
}
// Filter 2 : Black and White
Image Black_And_White_Filter2(Image img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += img(i, j, k);
            }
            avg /= 3;
            unsigned char color = (avg >= 128) ? 255 : 0;
            img(i, j, 0) = color;
            img(i, j, 1) = color;
            img(i, j, 2) = color;
        }
    }
    return img;
}
// Filter 3 : Invert Image
Image invertImage3(Image toedit)
{
    for (int i = 0;i < toedit.width;i++)
    {
        for (int j = 0;j < toedit.height;j++)
        {
            for (int k = 0;k < toedit.channels;k++)
            {
                toedit(i, j, k) = 255 - toedit(i, j, k);
            }
        }
    }
    return toedit;
}
// Filter 4 : Merge Image
Image MergeImages4(Image image1, Image image2) {
    int new_width = min(image1.width, image2.width);
    int new_height = min(image1.height, image2.height);
    Image image3(new_width, new_height);
    for (int i = 0;i < new_width;i++) {
        for (int j = 0;j < new_height;j++) {
            for (int k = 0;k < 3;k++) {
                int value = (image2(i, j, k) + image1(i, j, k)) / 2;
                image3(i, j, k) = value;
            }
        }
    }
    return image3;
}
// Filter 5 : Flip Image
Image flip_Horizontal5(Image& image) {
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width / 2; x++) {
            for (int k = 0; k < image.channels; k++) {
                unsigned char temp = image(x, y, k);
                image(x, y, k) = image(image.width - 1 - x, y, k);
                image(image.width - 1 - x, y, k) = temp;
            }
        }
    }
    return image;
}
Image flip_Vertical5(Image& image) {
    for (int y = 0; y < image.height / 2; y++) {
        for (int x = 0; x < image.width; x++) {
            for (int k = 0; k < image.channels; k++) {
                unsigned char temp = image(x, y, k);
                image(x, y, k) = image(x, image.height - 1 - y, k);
                image(x, image.height - 1 - y, k) = temp;
            }
        }
    }
    return image;
}
// Filter 6 : Rotate Image
Image rotateImage6(Image toedit, int rotat)
{

    if (rotat == 90)
    {
        Image freesz(toedit.height, toedit.width);
        for (int i = 0;i < toedit.width;i++)
        {
            for (int j = 0;j < toedit.height;j++)
            {
                for (int k = 0;k < toedit.channels;k++)
                {
                    freesz(j, i, k) = toedit(i, toedit.height - j, k);
                }
            }
        }
        return freesz;
    }
    else if (rotat == 180)
    {
        Image freesz(toedit.width, toedit.height);
        for (int i = 0;i < toedit.width;i++)
        {
            for (int j = 0;j < toedit.height;j++)
            {
                for (int k = 0;k < toedit.channels;k++)
                {
                    freesz(i, j, k) = toedit(toedit.width - i, toedit.height - j, k);
                }
            }
        }
        return freesz;
    }
    else if (rotat == 270)
    {
        Image freesz(toedit.height, toedit.width);
        for (int i = 0;i < toedit.width;i++)
        {
            for (int j = 0;j < toedit.height;j++)
            {
                for (int k = 0;k < toedit.channels;k++)
                {
                    freesz(j, i, k) = toedit(toedit.width - i, j, k);
                }
            }
        }
        return freesz;
    }
    else
    {
        cout << "Rotation angle 90,180,270" << endl;
        return toedit;
    }
}
// Filter 7: Darken / Lighten
Image derken(Image image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int value=image(i, j, k) *0.5;
                if (value < 0) {
                    value = 0;
                }
                if (value > 255) {
                    value = 255;
                }
                image(i, j, k) = value;
            }
        }
    }

    return image;
}
Image lighten(Image image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int value=image(i, j, k) *1.5;
                if (value < 0) {
                    value = 0;
                }
                if (value > 255) {
                    value = 255;
                }
                image(i, j, k) = value;
            }
        }
    }
    return image;

}

// Filter 8
Image cropImage8(Image &image, int x, int y, int newWidth, int newHeight)
{
    int width = image.width;
    int height = image.height;
    int channels = image.channels;

    if (x < 0 || y < 0 || x + newWidth > width || y + newHeight > height)
    {
        cout << "Invalid crop values!" << endl;
        return image;
    }

    Image cropped(newWidth, newHeight);

    for (int i = 0; i < newHeight; i++)
    {
        for (int j = 0; j < newWidth; j++)
        {
            for (int c = 0; c < channels; c++)
            {
                cropped(i, j, c) = image(x + i, y + j, c);
            }
        }
    }

    return cropped;
}

// Filter 9: Add Frame


Image frame9(Image toedit,int red,int green,int blue,int frame) {
    int scale =  max(2, (toedit.width + toedit.height) / 150);

    if(frame==1)
    {
        for(int i =0;i<scale;i+=1)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0)
                    {
                        toedit(i,j,k)=red;
                    }

                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =toedit.width-scale;i<toedit.width;i+=1)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=0;j<scale;j+=1)
            {
                for(int k=0;k<3;k++){
                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=toedit.height-scale;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }

    }
    if(frame==2)
    {

        for(int i =0;i<scale;i+=1)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0)
                    {
                        toedit(i,j,k)=red;
                    }

                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =scale;i<2*scale;i+=scale/3)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0)
                    {
                        toedit(i,j,k)=red;
                    }

                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =toedit.width-scale;i<toedit.width;i+=1)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =toedit.width-2*scale;i<toedit.width-scale;i+=scale/3)
        {
            for(int j=0;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }

        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=0;j<scale;j+=1)
            {
                for(int k=0;k<3;k++){
                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=scale;j<2*scale;j+=scale/3)
            {
                for(int k=0;k<3;k++){
                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }

        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=toedit.height-scale;j<toedit.height;j+=1)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }
        for(int i =0;i<toedit.width;i+=1)
        {
            for(int j=toedit.height-2*scale;j<toedit.height-scale;j+=scale/3)
            {
                for(int k=0;k<3;k++){

                    if(k==0){
                        toedit(i,j,k)=red;
                    }
                    else if(k==1){
                        toedit(i,j,k)=green;
                    }
                    else{
                        toedit(i,j,k)=blue;
                    }
                }
            }
        }

    }
    return toedit;
}


// Filter 10: Detect Edges
Image detect_Image_edges(Image img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += img(i, j, k);
            }
            avg /= 3;
            unsigned char color = (avg >= 128) ? 255 : 0;
            img(i, j, 0) = color;
            img(i, j, 1) = color;
            img(i, j, 2) = color;
        }
    }
    Image img2 = img;
    for (int i = 1; i < img.width-1; i++) {
        for (int j = 1; j < img.height-1; j++) {
            for (int k = 0; k < img.channels; k++) {
                if (img2(i-1,j-1,k)!=img2(i, j, k)||img2(i, j, k)!=img2(i+1,j+1,k)) {
                    img(i, j, k) = 0;
                }
                else {
                    img(i, j, k) = 255;
                }
            }
        }
    }
    return img;
}

// Filter 11: Resize Image
Image resizeImage11(Image& img, float scale) {
    int newWidth = img.width * scale;
    int newHeight = img.height * scale;

    if (newWidth <= 0 || newHeight <= 0)
    {
        cout << "Error: Invalid scale!" << endl;
        return img;
    }

    Image resized(newWidth, newHeight);

    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < newHeight; j++)
        {
            int oldX = i / scale;
            int oldY = j / scale;

            if (oldX >= img.width) oldX = img.width - 1;
            if (oldY >= img.height) oldY = img.height - 1;

            for (int k = 0; k < img.channels; k++)
            {
                resized(i, j, k) = img(oldX, oldY, k);
            }
        }
    }

    return resized;

}


// Filter 12: Blur Image
Image blurImage12(Image toedit)
{
    Image result(toedit.width,toedit.height);
    int scale =  max(2, (toedit.width + toedit.height) / 650);

    for (int i = scale;i<=toedit.width-(scale);i+=(scale))
    {
        for(int j=scale;j<=toedit.height-(scale);j+=(scale))
        {
            for(int k=0;k<3;k++){
                int avg=0;
                for(int m=-scale;m<(scale+1);m++){
                    for(int n=-scale;n<(scale+1);n++){
                        avg += toedit(i+n,j+m,k);
                    }
                }
                avg/=(((2 * scale)+1)*((2 * scale)+1));
                for(int m=-scale;m<=(scale);m++){
                    for(int n=-(scale);n<=(scale);n++){
                        result (i+n,j+m,k)=avg ;
                    }
                }
            }
        }
    }
    return result;

}
//filter 13
Image natural_sunlight(Image image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = min(255,image(i, j, 0)+35);
            image(i,j,1) = min(255,image(i,j,1)+55);
        }
    }
    return image;
}

// Filter 14
Image oilPaintFilter14(Image& img)
{
    Image result(img.width, img.height);

    int radius = 3;
    for (int y = 0; y < img.height; y++)
    {
        for (int x = 0; x < img.width; x++)
        {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;

            for (int dy = -radius; dy <= radius; dy++)
            {
                for (int dx = -radius; dx <= radius; dx++)
                {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < img.width && ny >= 0 && ny < img.height)
                    {
                        sumR += img(nx, ny, 0);
                        sumG += img(nx, ny, 1);
                        sumB += img(nx, ny, 2);
                        count++;
                    }
                }
            }
            result(x, y, 0) = sumR / count;
            result(x, y, 1) = sumG / count;
            result(x, y, 2) = sumB / count;
        }
    }
    return result;
}


Image Wano15(Image toedit)
{
    int scale =  max(2, (toedit.width + toedit.height) / 650);

    for (int i =0;i<toedit.width;i+=1)
    {
        for (int j =0;j<toedit.height;j+=scale)
        {
            for(int m=0;m<(scale+1)/2;m++){
                j++;
                for (int k =0;k<toedit.channels;k++)
                {

                    toedit(i,j,k)=toedit(i,j,k)-(toedit(i,j,k)*(0.35));

                }
            }
        }
    }
    return toedit;
}






