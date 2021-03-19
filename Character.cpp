#include "Character.h"
//constructor to initialize the position and velocity to character
Character::Character(){
  locationX = 0;
  locationY = 0;
  velX = 0;
  velY = 0;

}
//constructor to initialize the position and dimension of a character
Character::Character(double x, double y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
  velX = 0;
  velY = 0;
}
//getters
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
string Character::getPath(){
    return pathToImage;
}
bool Character::getFlagX(){
    return flagX;
}

bool Character::getFlagY(){
    return flagY;
}
// returns the rectangle of the character
SDL_Rect Character::getRect(){
    // collision box
    SDL_Rect mCollider = {(int) locationX, (int) locationY, width, height};
    return mCollider;
}

//setters
void Character::setLocationX(double x){
  locationX = x;
}

void Character::setLocationY(double y){
  locationY = y;
}
void Character::setVelX(double velxIn){
    velX = velxIn;
}

void Character::setVelY(double velyIn){
    velY = velyIn;
}
void Character::setFlagX(bool b){
    flagX = b;
}

void Character::setFlagY(bool b){
    flagY = b;
}
void Character::setHeight(int heightIn){
  height = heightIn;
}

void Character::setWidth(int widthIn){
  width = widthIn;
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

// move character left or right or up or down
void Character::move()
{
    //Move the character left or right
    locationX += velX;
    //Move the character up or down
    locationY += velY;
}



