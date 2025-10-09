#include <iostream>
#include <string>
#include<vector>
#include "Image_Class.h"
#include "filters.h"
#include "filters.cpp"
using namespace std;
/*
section 27,28

20240175 : filters 1,4,7,10,13
20242148 : filters 2,5,8,11,14
20242150 : filters 3,6,9,12,15

*/

int main() {
    string name;
    bool imageChanged=false;
    int taskNum,undoNum=0;
    vector<Image> undo(10);
    cout <<"Enter the Image name: ";
    cin>>name;
    Image photo(name);
    Image image = photo;
    undo[0]=photo;

    while (true)
    {
        bool imageChanged=false;
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
        cout << "for Oil Painting (Wano) enter 15" << endl;
        cout << "To save the image enter 16" << endl;
        cout << "To load new image enter 17" << endl;
        cout << "To undo last change enter 18" << endl;
        cout << "To exit enter 19" << endl;

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
        else if (taskNum == 6) {
            int anglerot;
            cout << "Enter the angle of rotation: ";
            cin >> anglerot;
            image = rotateImage6(image, anglerot);
        }

        else if(taskNum==7)
        {
            //function 7
        }
        else if(taskNum==8)
        {
            int x, y, newWidth, newHeight;
            cout << "Enter starting point (x y): ";
            cin >> x >> y;
            cout << "Enter new width and height: ";
            cin >> newWidth >> newHeight;

            image = cropImage8(image, x, y, newWidth, newHeight);
        }
        else if(taskNum==9) {
            {
                int color[3],frame;
                cout<<"Enter the color degree Red,Green,Blue in order"<<endl;
                for(int col=0;col<3;col++)
                    cin>>color[col];
                cout <<"Enter 1,2 "<<endl;
                cin>>frame;
                image = frame9(photo,color[0],color[1],color[2],frame);
                imageChanged=true;
            }
        }
        else if(taskNum==10)
        {
            //function 10
        }
        else if(taskNum==11)
        {
            float scale;
            cout << "Enter resize scale ( 0.5 for smaller, 2 for larger): ";
            cin >> scale;

            image = resizeImage11(image, scale);
        }
        else if(taskNum==12)
        {
            image = blurImage12(photo);
            imageChanged=true;
        }
        else if(taskNum==13)
        {

        }
        else if(taskNum==14)
        {
            image = oilPaintFilter14(image);
            imageChanged=true;

        }
        else if(taskNum==15)
        {
            image = Wano15(photo);
            imageChanged=true;
        }
        else if(taskNum==16)
        {

            string newname;
            cout <<"Enter the new name :";
            cin >> newname;
            image.saveImage(newname);
            continue;
        }
        else if(taskNum==17)
        {
            cout <<"Enter the Image name: ";
            cin>>name;
            photo.loadNewImage(name);
            continue;
        }
        else if(taskNum==18)
        {
            if (undoNum > 0)
            {
                undoNum--;
                image = undo[undoNum];
                cout << "Undo successful.\n";
            }
            else
            {
                cout << "No more undo steps available.\n";
            }
            continue;

        }
        else if(taskNum==19){
            break;
        }
        else
        {
            cout<<"Reload the image and choose number from menu."<<endl;
            continue;
        }
        if (imageChanged)
        {

            if (undoNum == 9)
            {
                for (int i = 0; i < 9; i++)
                {
                    undo[i] = undo[i + 1];
                }
                undo[9] = image;
            }
            else
            {
                undoNum++;
                undo[undoNum] = image;
            }
        }

    }
}