#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"
#include <iostream>


using namespace std;

int SCREEN_WIDTH = 1366;
int SCREEN_HEIGHT = 768;

//for test
#include <iostream>


//Cell of the vector returned downside, upside , rightside, leftside
vector<Cell> Level::checkAllDirections(){
   vector<Cell> checkResult;
   int Xloc = user.getXLocation();
   int Yloc = user.getYLocation();
   int newLocX = user.getXLocation()+ user.getVelX();
   int newLocY = user.getXLocation()+ user.getVelY();
   Cell flag = Cell::BACKGROUND;
   int height = user.getHeight();
   int width = user.getWidth();
   vector<vector<Cell>> ground = terrain.getGround();
   if( user.getVelY() > 0 ) {
        //checking downside
        for (int i = Xloc; i <= (Xloc + width); i++) {
            if( i > SCREEN_HEIGHT || (ground[newLocY][i] == Cell::GROUND)  ){
                flag = Cell::GROUND;
                break;
            }
            if (ground[newLocY][i] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
        flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }
    if(user.getVelY() < 0){
        // checking upside
        for (int i = Xloc ; i >= (Xloc + width); i++) {
            if( i < 0 || (ground[newLocY][i] == Cell::GROUND) ){
                flag = Cell::GROUND;
                break;
            }
            if (ground[newLocY][i] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
       flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }

    if( user.getVelX() > 0 ) {
        //checking rightside
        for (int i = Yloc; i <= (Yloc + height); i++) {
            if( i > SCREEN_WIDTH || (ground[i][newLocX] == Cell::GROUND) ){
                flag = Cell::GROUND;
                break;
            }
            if (ground[i][newLocX] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
        flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }
    if(user.getVelX() < 0){
        // checking leftside
        for (int i = (Yloc - height); i >= Yloc; i--) {
            if( i < 0 || (ground[i][newLocX] == Cell::GROUND) ) {
                flag = Cell::GROUND;
                break;
            }
            if (ground[i][newLocX] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
        flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }
    return checkResult;

}


// move the user
void Level::moveWithCollision2(){
    // move the user if he can move (if no ground/wall)
    vector<SDL_Rect> grounds = terrain.getGrounds();
    move(user,grounds);
    
    // check if there is a collision with a danger. 
    bool lost = false;
    for(SDL_Rect danger : terrain.getDangers()){
        if(checkCollision( danger, user.getRect() )){
            lost = true;
            break;
        }
    }

    // check also if the player meet a monster. 
    // we don't need to check if the user already lost.
    if(!lost){
        for(Monster* monster: monsters){
            if(checkCollision(monster->getRect(), user.getRect())){
                lost = true;
                break;
            }
        }
    }

    // decrease his life if there the player lost, and set the position of the player to its initial position
    if(lost){
        user.decreaseNumLife();
        user.setLocationX(startPosiX);
        user.setLocationY(startPosiY);
    }
}


// NOT USED ANYMORE. SEE WITH moveWithCollision2.
void Level::moveWithCollision(){
   vector<Cell> cells = checkAllDirections();


    //check if collision with danger
   if((user.getVelY() > 0 && cells.at(0) == Cell::DANGER) 
        ||(user.getVelY() < 0 && cells.at(1) == Cell::DANGER) 
        ||(user.getVelX() > 0 && cells.at(2) == Cell::DANGER)
        ||(user.getVelX() < 0 && cells.at(3) == Cell::DANGER)) {
           user.setLocationX(startPosiX);
           user.setLocationY(startPosiY);
           user.decreaseNumLife();
    }else{
        //check collision with ground
        if((user.getVelY() > 0 && cells.at(0) == Cell::GROUND) 
           || (user.getVelY() < 0 && cells.at(1) == Cell::GROUND)){
            user.setFlagY(false);
        }
        if((user.getVelX() > 0 && cells.at(2) == Cell::GROUND)
            ||(user.getVelX() < 0 && cells.at(3) == Cell::GROUND)){
            user.setFlagX(false);
        }
        user.move();
    }      

}

void Level::collisionWithStar(){
    int indexToRemove = -1;
    for(size_t i = 0; i < stars.size(); i++){
        if(checkCollision( stars[i]->getRect(), user.getRect())){
            indexToRemove = i;
            break;
        }
    }
    // let's remove the star catched
    if(indexToRemove != -1)
        stars.erase (stars.begin()+indexToRemove);
}


// return true if the 2 rectangle collapse.
bool Level::checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}



// set the new position of the character, or not move if there is a wall
void Level::move(Character& character, vector<SDL_Rect>& walls)
{   
    SDL_Rect temp = character.getRect();

    //Move the dot left or right
    character.setLocationX(character.getXLocation() + character.getVelX() );  
    temp.x = character.getXLocation();
    character.setFlagX(false); // say the character can move on X (for now)

    bool flag_collision = false;
    for(SDL_Rect wall : walls){
        if(checkCollision( temp, wall )){
            flag_collision = true;
            break;
        }
    }


    //If the character collided or went too far to the left or right
    if( ( character.getXLocation() < 0 ) || ( character.getXLocation() + character.getWidth() > SCREEN_WIDTH ) || flag_collision )
    {
        //Move back
        character.setLocationX( character.getXLocation() - character.getVelX());
        temp.x = character.getXLocation();
        character.setFlagX(true); // tell that the character couldn't move on X axis
    }

    //Move the dot up or down
    
    character.setLocationY(character.getYLocation() + character.getVelY() );
    temp.y = character.getYLocation();
    character.setFlagY(false);

    
    flag_collision = false;
    for(SDL_Rect wall : walls){
        if(checkCollision( temp, wall )){
            flag_collision = true;
            break;
        }
    }

    //If the dot collided or went too far up or down
    if( ( character.getYLocation() < 0 ) || ( character.getYLocation() + character.getHeight() > SCREEN_HEIGHT ) || flag_collision )
    {
        //Move back
        character.setLocationY( character.getYLocation() - character.getVelY());
        temp.y = character.getYLocation();
        character.setFlagY(true);
    }

}

Terrain Level::getTerrain(){
    return terrain;
}

Player& Level::getUser(){
    return user;
}

vector<Monster*> Level::getMonsters(){
    return monsters;
}

vector<Star*> Level::getStar(){
    return stars;
}


Level::Level(){
    // for this level, lets define the localisation of the monsters
    numberMonsters = 3;
    vector<int> xMinLim = {265, 366, 1132};
    vector<int> xMaxLim = {473, 663, 1366};


    for(int i = 0; i < numberMonsters; i++){
        monsters.push_back(new Monster(xMinLim[i], xMaxLim[i]));
    }

    //let's define the stars
    int numStars = 4;
    // {{441, 294, 30, 32}, {386, 64, 30, 32}, {631, 564, 30, 32}, {1333, 462, 30, 32}}
    vector<int> xloc = {441, 386, 631, 1333};
    vector<int> yloc = {294, 64, 564, 462};

    for(int i = 0; i < numStars; i++)
        stars.push_back(new Star(xloc[i], yloc[i]));
    
    
}



void Level::moveMonsters(){
    
    vector<SDL_Rect> walls = terrain.getGrounds();
    vector<SDL_Rect> dangers = terrain.getDangers();
    // the Dangers are perceived as wall in this game
    walls.insert(end(walls), begin(dangers), end(dangers));

    for(Monster* monster : monsters){
        move(*monster,walls);
        // if the monster didn't move, it means it has reched a wall., or it reaches its limit
        if(monster->getFlagX() 
               || monster->getXLocation() <= monster->getXminLim() +2
                || monster->getXLocation() >= monster->getXmaxLim() - 2)
        {
            monster->setVelX(-monster->getVelX());
            //cout << "monster location: " << monster->getXLocation() << " min:" << monster->getXminLim()  << " max::" <<  monster->getXmaxLim() <<endl;
        }

    }
}