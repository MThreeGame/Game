#ifndef PLAYER
#define PLAYER
class Player{
  private:
    string name;
    int score;
    int numLife;
    int locationX;
    int locationY;
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