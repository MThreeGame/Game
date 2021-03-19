#pragma once
#include <string>
#include "SDL.h"

using namespace std;


class Character{
  protected:
    double locationX;
    double locationY;
    int height = 68;
    int width = 28;
    //positionToX // |----------------| PreviousX minX maxX
    double velX, velY;
    //Maximum axis velocity of the dot
    double VELOCITY = 2.3;

    // flag = false if the character could move. flag = true if it couldn't move
    bool flagX = false;
    bool flagY = false;

    string pathToImage;
     

  public:
    Character();
    Character(double x, double y, int heightIn, int widthIn);

    //accessor
    double getXLocation();
    double getYLocation();
    int getHeight();
    int getWidth();
    string getPath();
    double getVelX();
    double getVelY();

    //mutator
    void setLocationX(double x);
    void setLocationY(double y);
    void setHeight(int heightIn);
    void setWidth(int widthIn);


    void increaseVelX();
    void decreaseVelX();
    void increaseVelY();
    void decreaseVelY();
    
    void setVelX(double velxIN);
    void setVelY(double velxIN);

    bool getFlagX();
    bool getFlagY();

    void setFlagX(bool b);
    void setFlagY(bool b);
    

    void move(); // update location depending of velocity


    SDL_Rect getRect();

};