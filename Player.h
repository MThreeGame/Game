#ifndef PLAYER
#define PLAYER

#include <string>
#include "Character.h"

using namespace std;


class Player: public Character{
  private:
    string name;
    int score;
    int numLife;

  
  public: 
    Player();
    Player(string pname, int x, int y);
    //getters
    int getXLocation();//////////////////////////////////////////////////////////IN CHARACTER TOO
    int getYLocation();
    int getScore();
    int getNumLife();
    //mutators
    void setNumLife(int number);
    void setScore(int scr);
      
};

#endif