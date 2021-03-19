#pragma once

#include "SDL.h"
#include <string>
#include <vector>

using namespace std;

class Star {

  public:
    Star(int posX, int posY);



    string getPath();
    //int getNumStar();
    //int getNumCatched();
    //vector <bool> getStarCatched();
    //void setStarCatched(int index);

    SDL_Texture* getGStar();
    SDL_Rect getRect();
    bool win();



    private:
      int posX;
      int posY;
      int width = 30;
      int height = 32;
      int numStar = 4;
      int numCatched = 0;
      string pathToImage = "../images/star.bmp";
      //vector <bool> starCatched = {{true}, {true}, {true}, {true}};

      SDL_Texture* gStar = NULL;

      //vector<SDL_Rect> starPosition = {{441, 294, 30, 32}, {386, 64, 30, 32}, {631, 564, 30, 32}, {1333, 462, 30, 32}};

};