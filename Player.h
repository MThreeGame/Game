#ifndef PLAYER
#define PLAYER

#include <string>

using namespace std;


class Player{
  private:
    string name;
    int score;
    int numLife;

    // position
    int locationX;
    int locationY;
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    string pathToImage = "../images/user1.bmp";

  public: 
    Player(string pname, int x, int y);
    //getters
    int getXLocation();
    int getYLocation();
    int getScore();
    int getNumLife();
    //mutators
    void setNumLife(int number);
    void setScore(int scr);
    void movePlayer(string key);
      
};

#endif