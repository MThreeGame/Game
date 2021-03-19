#include "Monster.h"
#include <random>

//constructor which defines a monster and put it in level
Monster::Monster(int xMinLim, int xMaxLim, string path):Character(){
    VELOCITY = 1;
    pathToImage = path;
    this->XminLim = xMinLim;
    this->XmaxLim = xMaxLim;
    locationX = XminLim + ( std::rand() % ( XmaxLim - XminLim + 1 ) );
    locationY = 0;
    height = 50;
    width = 50;
    // lets add a gravity
    velY = 1;
    // lets give us the direction right
    velX = VELOCITY;
}

Monster::Monster(string path):Character(){
    VELOCITY = 0.5;
    pathToImage = path;
    // lets use a random position for the X between 200 and 1366;
    // 200 is to be far enought of the player who is initialised to the position (0,0)
    // 1366 is the length of the background
    XminLim = 200 ;
    XmaxLim = 1366 ;
    locationX = XminLim + ( std::rand() % ( XmaxLim - XminLim + 1 ) );
    locationY = 0;
    height = 50;
    width = 50;
    // lets add a gravity
    velY = 1;
    // lets give us the direction right
    velX = VELOCITY;
}
//getters
int Monster::getXminLim(){
    return XminLim;
}

int Monster::getXmaxLim(){
    return XmaxLim;
}
//setters
void Monster::setXminLim(int input){
    XminLim = input;
}

void Monster::setXmaxLim(int input){
    XmaxLim = input;
}