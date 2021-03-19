#include "Terrain.h"
#include <iostream>
using namespace std;
/* READ THE IMAGE FROM THE FILE TO CREATE THE EQUIVALENT MATRIX
WARNING!!!!! The file must be a bmp of 3 values by pixels, not 4.
*/
/*
Let's decide :
DANGER : RED and BLACK
BACKGROUND : BLUE and WHITE
GROUND : everything else
let's define the color this way: (this is arbitrary decision, to accept some little variations)
RED : R > 200, G < 50, B < 50
BLACK : R < 20, G < 20, B < 20 
BLUE : B > 200, G < 30, R < 30
WHITE : R > 240, G > 240, B > 240

*/

//defines each pixel as a cell
Cell Terrain::pixelToCell(unsigned char B, unsigned char G, unsigned char R){
    
    //cout << (int)R << "/" << (int)G << "/" << (int)B << " ";
    // red
    if(R > 200 &&  G < 50 && B < 50)
        return Cell::DANGER;
    // black
    if(R < 20 && G < 20 && B < 20)
        return Cell::DANGER;
    // blue
    if(R < 30 && G < 30 && B > 200 )
        return Cell::BACKGROUND;
    // white
    if(R > 240 && G > 240 && B > 240)
        return Cell::BACKGROUND;

    return Cell::GROUND;
}


vector<vector<Cell>> Terrain::readBMP(const char* filename, int& width, int& height)
{
    vector<vector<Cell>> res;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f); 
    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];
    //cout << "width: " << width << endl;
    //cout << "height: " << height << endl;
    // allocate 3 bytes per pixel
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size];
    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f); 
    fclose(f);

    /* in fact this gives (B, G, R) and nor (RGB)
        a pixel is stored in:
        data[3 * (i * width + j)], 
        data[3 * (i * width + j) + 1]
        data[3 * (i * width + j) + 2].*/
    /*
    for(int i = 0; i < height; i ++){
        vector<Cell> tempVect;
        for (int j = 0; j < width; j ++){
            tempVect.push_back(pixelToCell( data[3 * (i * width + j)],
                                            data[3 * (i * width + j) + 1],
                                            data[3 * (i * width + j) + 2]));
        }
        res.push_back(tempVect);
    }*/
    // apparently the image seems reverse.
    for(int i = height -1; i >= 0; i--){
        vector<Cell> tempVect;
        for (int j = width - 1; j >= 0; j--){
            tempVect.push_back(pixelToCell( data[3 * (i * width + j)],
                                            data[3 * (i * width + j) + 1],
                                            data[3 * (i * width + j) + 2]));
        }
        res.push_back(tempVect);
    }

    //display the vector
    /*
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++)
            cout <<res[i][j] << " ";
        cout << endl;
    }
    */
    return res;
}

// constructor
Terrain::Terrain(){
    int width;
    int height;
    //ground = readBMP(pathToImage.c_str(), width, height);
    // add of the SDL_grounds for MapTest2.bmp
    SDL_Rect rect1 = {88,169, 131, 50};
    grounds.push_back(rect1);
    SDL_Rect rect2 = {341, 98, 108, 53};
    grounds.push_back(rect2);
    SDL_Rect rect3 = {265, 328, 208, 62};
    grounds.push_back(rect3);
    SDL_Rect rect4 = {572, 265, 210, 64};
    grounds.push_back(rect4);
    SDL_Rect rect5 = {890, 302, 127, 59};
    grounds.push_back(rect5);
    SDL_Rect rect6 = {0, 536, 366, 232};
    grounds.push_back(rect6);
    SDL_Rect rect7 = {366, 599, 297, 169};
    grounds.push_back(rect7);
    SDL_Rect rect8 = {860, 595, 472, 173};
    grounds.push_back(rect8);
    SDL_Rect rect9 = {1132, 496, 234, 272};
    grounds.push_back(rect9);
    // let's create the dangers
    SDL_Rect rect10 = {663, 670, 196, 96};
    dangers.push_back(rect10);
    SDL_Rect rect11 = {1084, 553, 50, 42};
    dangers.push_back(rect11);
}

// getters
vector<vector<Cell>> Terrain::getGround(){
    return ground;
}
vector<SDL_Rect> Terrain::getGrounds(){
    return grounds;
}

vector<SDL_Rect> Terrain::getDangers(){
    return dangers;
}

string Terrain::getPathToImage(){
    return pathToImage;
}
