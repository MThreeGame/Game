#pragma once
#include <string>
#include "SDL.h"

using namespace std;


class Character{
  protected:
    int locationX;
    int locationY;
    int height = 68;
    int width = 28;
    //positionToX // |----------------| PreviousX minX maxX
    int velX, velY;
    //Maximum axis velocity of the dot
    static const int VELOCITY = 5;

    string pathToImage;
     

  public:
    Character();
    Character(int x, int y, int heightIn, int widthIn);

    //accessor
    int getLocationX();
    int getLocationY();
    int getHeight();
    int getWidth();
    string getPath();
    int getVelX();
    int getVelY();

    //mutator
    void setLocationX(int x);
    void setLocationY(int y);
    void setHeight(int heightIn);
    void setWidth(int widthIn);


    void increaseVelX(double percent = 1.);
    void decreaseVelX(double percent = 1.);
    void increaseVelY(double percent  = 1.);
    void decreaseVelY(double percent = 1.);

    void move(); // update location depending of velocity


    SDL_Rect getRect();




};