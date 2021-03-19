#pragma once

#include "SDL.h"

/*  a terrain is a matrix of Cell

   */

#include <string>
#include <vector>
#include "SDL.h"
#include "Cell.h"

using namespace std;

class Terrain{
    private:
        /** if we want to use a matrix initialised by the image:*/
        vector<vector<Cell>> ground;
        

        vector<SDL_Rect> grounds;
        vector<SDL_Rect> dangers;

        string pathToImage = "../images/MapTest2.bmp";


        /* Functions to read a bmp file and create the grounds */
        Cell pixelToCell(unsigned char B, unsigned char G, unsigned char R);

        vector<vector<Cell>> readBMP(const char* filename, int& width, int& height);


    public:
        Terrain(); // can be initialized with a binary image file ?

        vector<vector<Cell>> getGround();
        vector<SDL_Rect> getGrounds();
        vector<SDL_Rect> getDangers();

        string getPathToImage();
    
};