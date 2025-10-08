#include <iostream>
#include <string>
#include <vector>
#include "Image_Class.h"
#include <algorithm>
using namespace std;


Image invertImage3(Image toedit)
{
    for (int i =0;i<toedit.width;i++)
    {
        for (int j =0;j<toedit.height;j++)
        {
            for (int k =0;k<toedit.channels;k++)
            {
                toedit(i,j,k)=255-toedit(i,j,k);
           }
        }
    }
    return toedit;
}
Image rotateImage6(Image toedit,int rotat)
{

    if(rotat==90)
    {
       Image freesz(toedit.height,toedit.width);
        for (int i =0;i<toedit.width;i++)
        {
            for (int j =0;j<toedit.height;j++)
            {
                for (int k =0;k<toedit.channels;k++)
                {
                freesz(j,i,k)=toedit(i,toedit.height-j,k);
                }
            }
        }
        return freesz;
    }
    else if(rotat==180)
    {
        Image freesz(toedit.width,toedit.height);
        for (int i =0;i<toedit.width;i++)
        {
            for (int j =0;j<toedit.height;j++)
            {
                for (int k =0;k<toedit.channels;k++)
                {
                freesz(i,j,k)=toedit(toedit.width-i,toedit.height-j,k);
                }
            }
        }
        return freesz;
    }
    else if(rotat==270)
    {
        Image freesz(toedit.height,toedit.width);
        for (int i =0;i<toedit.width;i++)
        {
            for (int j =0;j<toedit.height;j++)
            {
                for (int k =0;k<toedit.channels;k++)
                {
                freesz(j,i,k)=toedit(toedit.width-i,j,k);
                }
            }
        }
        return freesz;
    }
    else
    {
        cout<<"Rotation angle 90,180,270"<<endl;
        return toedit;
    }
}

int main()
{
    string name;
    bool imageChanged=false;
    int taskNum,undoNum=0;
    vector<Image> undo(10);
    cout <<"Enter the Image name: ";
    cin>>name;
    Image photo(name),image;
    undo[0]=photo;
    while(true)
    {
    bool imageChanged=false;
    cout<<"Menu:\n";
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
    cout <<"for sunlight enter 13"<<endl;
    cout <<"for oil painting enter 14"<<endl;
    cout <<"for old Den Den Mushi Images enter 15"<<endl;
    cout <<"To save the image enter 16"<<endl;
    cout <<"To load new image enter 17"<<endl;
    cout <<"To undo max 10 enter 18"<<endl;
    cout <<"To exist enter 19"<<endl;

    cin >>taskNum;

    if(taskNum==1)
    {
        //function 1
    }
    else if(taskNum==2)
    {
        //function 2
    }
    else if(taskNum==3)
    {
        image=invertImage3(photo);
        imageChanged=true;
    }
    else if(taskNum==4)
    {
        //function 4
    }
    else if(taskNum==5)
    {
        //function 5
    }
    else if(taskNum==6)
    {
        int anglerot;
        cout<<"Enter the angle of rotation: ";
        cin >>anglerot;
        image=rotateImage6(photo,anglerot);
        imageChanged=true;
    }
    else if(taskNum==7)
    {
        //function 7
    }
    else if(taskNum==8)
    {
        //function 8
    }
    else if(taskNum==9)
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
    else if(taskNum==10)
    {
        //function 10
    }
    else if(taskNum==11)
    {
        //function 11
    }
    else if(taskNum==12)
    {
        image = blurImage12(photo);
        imageChanged=true;
    }
    else if(taskNum==13)
    {
        //function 13
    }
    else if(taskNum==14)
    {
        //function 14
    }
    else if(taskNum==15)
    {
        image = Wano15(photo);
        imageChanged=true;
    }
    else if(taskNum==16)
    {
        //save image
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
