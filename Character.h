#pragma once
#include <string>

using namespace std;


class Character{
  protected:
    int locationX;
    int locationY;
    int height;
    int width;
    //positionToX // |----------------| PreviousX minX maxX ?

    int velX, velY;
    //Maximum axis velocity of the dot
    static const int VELOCITY = 10;

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

    //mutator
    void setLocationX(int x);
    void setLocationY(int y);
    void setHeight(int heightIn);
    void setWidth(int widthIn);

    void increaseVelX();
    void decreaseVelX();
    void increaseVelY();
    void decreaseVelY();

    void move(); // update location




};