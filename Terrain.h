#pragma once

/*  a terrain is a matrix of Cell

   */

#include <string>
#include <vector>
#include "SDL.h"
#include "Cell.h"

using namespace std;

class Terrain{
  private:
      //matrix
      //int height;
      //int weight;
      //int[][] matrix;


      vector<vector<Cell>> ground;

      string pathToImage = "../images/MapTest.bmp";


      /* Functions to read a bmp file and create the grounds */
      Cell pixelToCell(unsigned char B, unsigned char G, unsigned char R);

     vector<vector<Cell>> readBMP(const char* filename, int& width, int& height);


  public:
      Terrain(); // can be initialized with a binary image file ?

      //vector<SDL_Rect> getGrounds();
      vector<vector<Cell>> getGround();

      string getPathToImage();

      // return the type of the location : if it is a ground or background
      // or something else ?
      //int getTypeAtPosition(int xLocation, int yLocation);
    
};