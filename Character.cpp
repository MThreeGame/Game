#include "Character.h"



Character::Character(){
  locationX = 0;
  locationY = 0;
  velX = 0;
  velY = 0;

}



Character::Character(double x, double y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
  velX = 0;
  velY = 0;
}

double Character::getXLocation(){
  return locationX;
}
double Character::getYLocation(){
  return locationY;
}

int Character::getHeight(){
  return height;
}

int Character::getWidth(){
  return width;
}
double Character::getVelX(){
    return velX;
}
double Character::getVelY(){
    return velY;
}
void Character::setLocationX(double x){
  locationX = x;
}

void Character::setLocationY(double y){
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

  void Character::setVelX(double velxIn){
    velX = velxIn;
  }

  void Character::setVelY(double velyIn){
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
    SDL_Rect mCollider = {(int) locationX, (int) locationY, width, height};

    return mCollider;   

}


