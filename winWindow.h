//
// Created by admin on 2021-03-18.
//
#ifndef GAME_WINWINDOW_H
#define GAME_WINWINDOW_H
#include "SDL.h"
#include <string>

using namespace std;
class winWindow {
   public:
    winWindow(){}
    //Starts up SDL and creates window
    bool init();
    //Loads media : load all the images for the different object represenations
    bool loadMedia();
    //Frees media and shuts down SDL
    void close();
    //Loads individual image as SDL_Surface. Not used anymore.
    SDL_Surface* loadSurface(string path);


    //void blitSurface();
   private:
    // ATTRIBUTES
    // size of the window,
    int SCREEN_WIDTH = 500;
    int SCREEN_HEIGHT = 400;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //The window renderer
    SDL_Renderer* gRenderer = NULL;

};

#endif //GAME_WINWINDOW_H
