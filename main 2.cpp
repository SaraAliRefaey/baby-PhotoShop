#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

Image Grayscale_Conversion(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int ave=0;
            for (int k = 0; k < image.channels; k++) {
                ave+=image(i,j,k);

            }
            ave=ave/3;
            for (int k = 0; k < 3; k++) {
                image(i,j,k)=ave;
            }
        }
    }
        return image;
}

Image MergeImages(Image image1 ,Image image2) {
    int new_width=min(image1.width,image2.width);
    int new_height=min(image1.height,image2.height);
    Image image3(new_width,new_height);
    for(int i=0;i<new_width;i++) {
        for(int j=0;j<new_height;j++) {
            for(int k=0;k<3;k++) {
                int value=(image2(i,j,k)+image1(i,j,k))/2;
                image3(i,j,k)=value;
            }
        }
    }
    return image3;
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
        cout <<"To exit enter 15"<<endl;

        cin >>taskNum;

        if(taskNum==1)
        {
            image = Grayscale_Conversion(image);
        }
     
        else if(taskNum==4)
        {
            cout << "Enter the second image name: ";
            string name2;
            cin >> name2;
            Image img2(name2);
            image = MergeImages(image, img2);

        }

        else if(taskNum==13)
        {
            string newname;
            cout << "Enter the new filename (without extension): ";
            cin >> newname;

            int formatChoice;
            cout << "Choose format: 1 = JPG, 2 = PNG, 3 = BMP\n";
            cin >> formatChoice;

            if (formatChoice == 1) {
                newname += ".jpg";
            } else if (formatChoice == 2) {
                newname += ".png";
            } else if (formatChoice == 3) {
                newname += ".bmp";
            } else {
                cout << "Invalid choice, saving as JPG by default.\n";
                newname += ".jpg";
            }

            image.saveImage(newname);
            cout << "Image saved as " << newname << endl;
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
}
