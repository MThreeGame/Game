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

int Character::getXLocation(){
  return locationX;
}
int Character::getYLocation(){
  return locationY;
}

int Character::getHeight(){
  return height;
}

int Character::getWidth(){
  return width;
}
int Character::getVelX(){
    return velX;
}
int Character::getVelY(){
    return velY;
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

  void Character::setVelX(int velxIn){
    velX = velxIn;
  }
  void Character::setVelY(int velyIn){
    velY = velyIn;
  }

    bool Character::getFlagX(){
      return flagX;
    }

    bool Character::getFlagY(){
      return flagY;
    }

    void Character::setFlagX(bool b){
      flagX = b;
    }

    void Character::setFlagY(bool b){
      flagY = b;
    }

void Character::move()
{
    //Move the dot left or right
    locationX += velX;


    //Move the dot up or down
    locationY += velY;

}



SDL_Rect Character::getRect(){
    // collision box
    SDL_Rect mCollider = {locationX, locationY, width, height};

    return mCollider;   

}


