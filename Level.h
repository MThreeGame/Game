#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Terrain.h"
#include "Monster.h"
#include "Star.h"



class Level:
  private:
      int currentLevel = 0;
      vector<Terrain> terrains; // we use the terrain at index currentLevel
      vectors <Monter*> monsters;
      vectors <Star> stars; // something to catch 



  public:
      




#endif