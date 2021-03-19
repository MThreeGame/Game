#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Terrain.h"
#include "Monster.h"
#include "Star.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"



class Level{
  private:
      int currentLevel = 0;
      //vector<Terrain> terrains; // we use the terrain at index currentLevel
      Terrain terrain;
      int numberMonsters = 3;
      vector<Monster*> monsters;
      Player user;
      Star stars;
      int startPosiX = 0;
      int startPosiY = 0;
      //vector<Star> stars; // something to catch 

      bool checkCollision( SDL_Rect a, SDL_Rect b );



  public:
    // constructor.
    // initialise a number of monsters.
    Level();

    // NOT USED ANYMORE
    // return the type of collisions for each side of the user
    // return as a Cell for each side. If no collision then return Cell::BACKGROUND
    // order of the sides return : DOWN, UP , RIGHT, LEFT
    vector<Cell> checkAllDirections();

    // NOT USED ANYMORE
    // Move the position of the user depending of the velocity,
    // with a check of the collisions. the user lose a life if collision with DANGER
    // and its position is set to 0.
    void moveWithCollision();
    // same as moveWithCollision(), but the terrain is composed by different SDL_Rect
    // and not a matrix
    void moveWithCollision2();

    //Check if the player comes in collsion with the star
    void collisionWithStar();


    // move the monsters. change direction if there is a wall.
    void moveMonsters();


    Terrain getTerrain();

    vector<Monster*> getMonsters();

    Player& getUser();

    Star& getStar();

    void move(Character& character, vector<SDL_Rect>& walls);

};


#endif