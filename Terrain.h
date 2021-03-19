#pragma once

#include "SDL.h"
#include <string>
#include <vector>
#include "SDL.h"
#include "Cell.h"
using namespace std;
//  a terrain is a matrix of Cell
class Terrain{
    private:
       vector<vector<Cell>> ground;
       vector<SDL_Rect> grounds;
       vector<SDL_Rect> dangers;
       string pathToImage = "../images/MapTest2.bmp";
       /* Functions to read a bmp file and create the grounds */
       Cell pixelToCell(unsigned char B, unsigned char G, unsigned char R);
       vector<vector<Cell>> readBMP(const char* filename, int& width, int& height);
    public:
        Terrain();
        vector<vector<Cell>> getGround();
        vector<SDL_Rect> getGrounds(); // returns a vector of the grounds
        vector<SDL_Rect> getDangers(); //returns a vector of dangers
        string getPathToImage();
};