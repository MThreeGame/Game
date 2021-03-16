#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Terrain.h"
#include "Monster.h"
//#include "Star.h"
#include "SDL.h"
#include "Player.h"



class Level{
  private:
      int currentLevel = 0;
      //vector<Terrain> terrains; // we use the terrain at index currentLevel
      Terrain terrain;
      vector<Monster*> monsters;
      Player user;
      //vector<Star> stars; // something to catch 

      bool checkCollision( SDL_Rect a, SDL_Rect b );



  public:

    string checkCollisions( Player player);

    Terrain getTerrain();

    Player getUser();
      

};


#endif