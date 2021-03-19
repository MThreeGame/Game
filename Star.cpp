#include "Star.h"

string Star::getPath(){
    return pathToImage;
}
SDL_Rect Star::getRect(){
    // collision box
    SDL_Rect mCollider = {posX, posY, width, height};

    return mCollider;   

}
Star::Star(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}