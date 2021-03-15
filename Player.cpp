
#include <string>
#include "Player.h"



//constructor
Player::Player(string pname, int x, int y):Character(){
   name = pname;
   locationX = x;
   locationY = y; 
}
Player::Player():Character(){ // call the constructor of the base class
    pathToImage = "../images/user1.bmp";

}




//getters
int Player::getXLocation(){
  return locationX;
}
int Player::getYLocation(){
  return locationY;
}
int Player::getScore(){
    return score;
}
int Player::getNumLife(){
  return numLife;
}
//mutators
void Player::setNumLife(int number){
  numLife = number;
}
void Player::setScore(int scr){
  score = scr;
}




