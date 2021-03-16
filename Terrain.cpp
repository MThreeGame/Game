#include "Terrain.h"




Terrain::Terrain(){
    // let's initialise one rectangle 
    //Set the wall
    SDL_Rect wall;
    wall.x = 30;
    wall.y = 40;
    wall.w = 40;
    wall.h = 20;

    grounds.push_back(wall);
}


vector<SDL_Rect> Terrain::getGrounds(){
    return grounds;
}

