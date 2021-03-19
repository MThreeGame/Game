#pragma once

#include "SDL.h"
#include <string>

using namespace std;

class Star {

  public:
    //Constructor of Star with the X and Y position in window
    Star(int posX, int posY);
    
    //Return the path of the image of the star
    string getPath();

    SDL_Texture* getGStar();
    SDL_Rect getRect();
    bool win();

    private:
      //Position of the star in window
      int posX;
      int posY;
      //Dimension of the star
      int width = 30;
      int height = 32;
      //Path to image in folder
      string pathToImage = "../images/star.bmp";
};