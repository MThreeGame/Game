#include "Character.h"


Character::Character(int x, int y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
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

int Character::getwidth(){
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