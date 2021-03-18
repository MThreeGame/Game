#pragma once

#include "SDL.h"
#include <string>
#include <vector>

using namespace std;

class Star {

  public:
    string getPath();
    int getNumStar();
    int getNumCatched();
    vector <bool> getStarCatched();
    void setStarCatched(int index);
    SDL_Texture* getGStar();
    vector<SDL_Rect> getStarPosition();
    bool win();



    private:
      int numStar = 4;
      int numCatched = 0;
      string pathToImage = "../images/star.bmp";
      vector <bool> starCatched = {{true}, {true}, {true}, {true}};

      SDL_Texture* gStar = NULL;

      vector<SDL_Rect> starPosition = {{441, 294, 30, 32}, {386, 64, 30, 32}, {631, 564, 30, 32}, {1333, 462, 30, 32}};

};