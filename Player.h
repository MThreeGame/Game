#ifndef PLAYER
#define PLAYER
#include <string>
#include "Character.h"
using namespace std;
//class player that inherits from class character
class Player: public Character{
  private:
    string name;
    // increase when catch a star
    int score = 0;
    // decrease if meet a monster or Cell::DANGER / terrain.dangers
    int numLife = 4;
  public:
    Player();
    Player(string pname, int x, int y);
    //getters
    int getScore();
    int getNumLife();
    //mutators
    void decreaseNumLife();
    bool isAlive();
    void setScore(int scr);
      
};

#endif