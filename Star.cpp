#include "Star.h"
/*
Star::Star(int x, int y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
  velX = 0;
  velY = 0;
}
*/

string Star::getPath(){
    return pathToImage;
}
// returns the rectangle that the star is in
SDL_Rect Star::getRect(){
    // collision box
    SDL_Rect mCollider = {posX, posY, width, height};

    return mCollider;   

}
//sets the star position
Star::Star(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}