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
    int VELOCITY = 2;

    // flag = false if the character could move. flag = true if it couldn't move
    bool flagX = false;
    bool flagY = false;

    string pathToImage;
     

  public:
    Character();
    Character(int x, int y, int heightIn, int widthIn);

    //accessor
    int getXLocation();
    int getYLocation();
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


    void increaseVelX();
    void decreaseVelX();
    void increaseVelY();
    void decreaseVelY();
    
    void setVelX(int velxIN);
    void setVelY(int velxIN);

    bool getFlagX();
    bool getFlagY();

    void setFlagX(bool b);
    void setFlagY(bool b);
    

    void move(); // update location depending of velocity


    SDL_Rect getRect();




};