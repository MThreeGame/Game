#pragma once

#include "Character.h"

class Monster : public Character{
  private:
  // we keep the last velocity to know its last move.
  // the monster keep the same move 
  // until it reaches a XMin, or XMax.
  // we can change it to reach a wall if we want to make it work for any terrain

  // then it changes to the opposite direction.
  // for now the monster only move on the X axis.
  // but have gravity.
  // we initialise the first move to go to the right


    int XminLim;
    int XmaxLim;


  public:
  // to initialise the monster and be sure to be on the background
  // we can drop them from the sky. 
  // we put an random number for the X-axis
  // then Yposition = 0
  // we add the gravity so the monster will fall 
  // until it reaches the ground. 
    Monster(string path = "../images/monster.bmp");
    Monster(int xMinLim, int xMaxLim, string path = "../images/monster.bmp");



    int getXminLim();
    int getXmaxLim();
    void setXminLim(int input);
    void setXmaxLim(int input);

};

