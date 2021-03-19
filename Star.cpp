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





SDL_Rect Star::getRect(){
    // collision box
    SDL_Rect mCollider = {posX, posY, width, height};

    return mCollider;   

}


Star::Star(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}