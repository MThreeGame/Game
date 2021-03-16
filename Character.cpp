#include "Character.h"



Character::Character(){
  locationX = 0;
  locationY = 0;
  velX = 0;
  velY = 0;

}



Character::Character(int x, int y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
  velX = 0;
  velY = 0;
}

int Character::getLocationX(){
  return locationX;
}

int Character::getLocationY(){
  return locationY;
}
int Character::getHeight(){
  return height;
}

int Character::getWidth(){
  return width;
}

void Character::setLocationX(int x){
  locationX = x;
}

void Character::setLocationY(int y){
  locationY = y;
}

void Character::setHeight(int heightIn){
  height = heightIn;
}

void Character::setWidth(int widthIn){
  width = widthIn;
}


string Character::getPath(){
  return pathToImage;
}

// Change the velocity. 
void Character::increaseVelX(){
  velX += VELOCITY;
}

void Character::decreaseVelX(){
  velX -= VELOCITY;
}



void Character::increaseVelY(){
  velY += VELOCITY;
}


void Character::decreaseVelY(){
  velY -= VELOCITY;
}

void Character::move()
{
    //Move the dot left or right
    locationX += velX;

  /* TODO
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
  */

    //Move the dot up or down
    locationY += velY;

    /* TODO
    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    } */


}



SDL_Rect Character::getRect(){
    // collision box
    SDL_Rect mCollider = {locationX, locationY, width, height};

    return mCollider;   

}


