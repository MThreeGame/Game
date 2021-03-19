#include <string>
#include "Player.h"
//constructor that sets the name and position of a player
Player::Player(string pname, int x, int y):Character(){
   name = pname;
   locationX = x;
   locationY = y; 
}
//loads the image of the player
Player::Player():Character(){ // call the constructor of the base class
    pathToImage = "../images/user1.bmp";
    velY = 1;
}
//getters
int Player::getScore(){
    return score;
}
int Player::getNumLife(){
  return numLife;
}
//mutators
void Player::decreaseNumLife(){
  numLife -= 1;
}
void Player::setScore(int scr){
  score = scr;
}
//checks the number of lives of the player if he is still alive returns true
bool Player::isAlive(){
  return numLife > 0;
}




