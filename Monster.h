#pragma once

#include "Character.h"

class Monster : public Character{
  private:
  // we keep the last velocity to know its last move.
  // the monster keep the same move 
  // until it reaches a wall/cell::GROUND.
  // then it changes to the opposite direction.
  // for now the monsster only move on the X axis.
  // we initialise the first move to go to the right

    int lastXVel = VELOCITY;
    int lastYVel = VELOCITY;


  public:
  // to initialise the monster and be sure to be on the background
  // we can drop them from the sky. 
  // we put an random number for the X-axis
  // then Yposition = 0
  // we add the gravity so the monster will fall 
  // until it reaches the ground. 
    Monster(string path = "../images/monster.bmp");

};

