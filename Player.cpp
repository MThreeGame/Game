string name;
    int score;
    int numLife;
    int locationX;
    int locationY;
//constructor
Player::Player(string pname, int x, int y){
   name = pname;
   locationX = x;
   locationY = y; 
}
//getters
int Player::getXLocation(){
  return locationX;
}
int Player::getYLocation(){
  return locationY;
}
int getScore(){
    return score;
}
int getNumLife(){
  return numLife;
}
//mutators
void Player::setNumLife(int number){
  numLife = number;
}
void Player::setScore(int scr){
  score = scr;
}
void movePlayer(string key){
  
}