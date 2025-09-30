#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

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


int main()
{
    string name;
    int taskNum;
    cout <<"Enter the Image name: ";
    cin>>name;
    Image photo(name), image;
    image = photo;

    while(true)
    {
        cout <<"for Gray scale Conversion enter 1"<<endl;
        cout <<"for Black and White enter 2"<<endl;
        cout <<"for Invert Image enter 3"<<endl;
        cout <<"for Merge Images enter 4"<<endl;
        cout <<"for Flip Image enter 5"<<endl;
        cout <<"for Rotate Image enter 6"<<endl;
        cout <<"for Darken and Lighten Image enter 7"<<endl;
        cout <<"for Crop Images enter 8"<<endl;
        cout <<"for Adding a Frame to the Picture enter 9"<<endl;
        cout <<"for Detect Image Edges enter 10"<<endl;
        cout <<"for Resizing Images enter 11"<<endl;
        cout <<"for Blur Images enter 12"<<endl;
        cout <<"To save the image enter 13"<<endl;
        cout <<"To load new image enter 14"<<endl;
        cout <<"To exist enter 15"<<endl;

        cin >>taskNum;

        if(taskNum==1)
        {
            // function 1
        }
        else if(taskNum==2)
        {
            image = Black_And_White_Filter2(image);
        }


        else if(taskNum==5)
        {
            int choice;
            cout << "Enter 1 for Horizontal Flip or 2 for Vertical Flip: ";
            cin >> choice;
            if (choice == 1) {
                image = flip_Horizontal5(image);
            } else if (choice == 2) {
                image = flip_Vertical5(image);
            } else {
                cout << "Invalid choice for flip.\n";
                continue;
            }
        }

        else if(taskNum==13)
        {
            string newname;
            cout <<"Enter the new name :";
            cin >> newname;
            image.saveImage(newname);
        }
        else if(taskNum==14)
        {
            cout <<"Enter the Image name: ";
            cin>>name;
            photo.loadNewImage(name);
            image = photo;
        }
        else if(taskNum==15)
        {
            break;
        }
        else
        {
            cout<<"Reload the image and choose number from menu.";
            continue;
        }
    }