#include <iostream>
#include <string>
#include "Image_Class.h"
#include "filters.h"
#include "filters.cpp"
using namespace std;
/*
section 27,28

20240175 : filters 1,4,7,10
20242148 : filters 2,5,8,11
20242150 : filters 3,6,9,12

*/

int main()
{
    string name;
    int taskNum;
    cout << "Enter the Image name: ";
    cin >> name;
    Image photo(name), image;
    image = photo;

    while (true)
    {
        cout << "for Gray scale Conversion enter 1" << endl;
        cout << "for Black and White enter 2" << endl;
        cout << "for Invert Image enter 3" << endl;
        cout << "for Merge Images enter 4" << endl;
        cout << "for Flip Image enter 5" << endl;
        cout << "for Rotate Image enter 6" << endl;
        cout << "for Darken and Lighten Image enter 7" << endl;
        cout << "for Crop Images enter 8" << endl;
        cout << "for Adding a Frame to the Picture enter 9" << endl;
        cout << "for Detect Image Edges enter 10" << endl;
        cout << "for Resizing Images enter 11" << endl;
        cout << "for Blur Images enter 12" << endl;
        cout << "To save the image enter 13" << endl;
        cout << "To load new image enter 14" << endl;
        cout << "To exit enter 15" << endl;

        cin >> taskNum;

        if (taskNum == 1)
        {
            image =  Grayscale_Filter1(image);
        }
        else if (taskNum == 2)
        {
            image = Black_And_White_Filter2(image);
        }
        else if (taskNum == 3)
        {
            image = invertImage3(image);
        }
        else if (taskNum == 4)
        {
            cout << "Enter the second image name: ";
            string name2;
            cin >> name2;
            Image img2(name2);
            image = MergeImages4(image, img2);

        }
        else if (taskNum == 5)
        {
            int choice;
            cout << "Enter 1 for Horizontal Flip or 2 for Vertical Flip: ";
            cin >> choice;
            if (choice == 1) {
                image = flip_Horizontal5(image);
            }
            else if (choice == 2) {
                image = flip_Vertical5(image);
            }
            else {
                cout << "Invalid choice for flip.\n";
                continue;
            }
        }
        else if (taskNum == 6)
        {
            int anglerot;
            cout << "Enter the angle of rotation: ";
            cin >> anglerot;
            image = rotateImage6(image, anglerot);
        }
     


        else if (taskNum == 13)
        {
            string newname;
            cout << "Enter the new filename (without extension): ";
            cin >> newname;

            int formatChoice;
            cout << "Choose format: 1 = JPG, 2 = PNG, 3 = BMP\n";
            cin >> formatChoice;

            if (formatChoice == 1) {
                newname += ".jpg";
            }
            else if (formatChoice == 2) {
                newname += ".png";
            }
            else if (formatChoice == 3) {
                newname += ".bmp";
            }
            else {
                cout << "Invalid choice, saving as JPG by default.\n";
                newname += ".jpg";
            }

            image.saveImage(newname);
            cout << "Image saved as " << newname << endl;
        }
        else if (taskNum == 14)
        {
            cout << "Enter the Image name: ";
            cin >> name;
            photo.loadNewImage(name);
            image = photo;
        }
        else if (taskNum == 15)
        {
            break;
        }
        else
        {
            cout << "Reload the image and choose number from menu.";
            continue;
        }
    }
}
