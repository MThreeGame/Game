#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"
int SCREEN_WIDTH = 1366;
int SCREEN_HEIGHT = 768;
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

bool encounterMonster(int xLoc, int yLoc, Cell cell){

}
// can be user later for check the collision between the player and the monsters
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

void Level::move(Player player,SDL_Rect& wall)
{   SDL_Rect temp = player.getRect();
    //Move the dot left or right
    player.setLocationX(player.getXLocation() + player.getVelX() );
    temp.x = player.getXLocation();
    //If the character collided or went too far to the left or right
    if( ( player.getXLocation() < 0 ) || ( player.getXLocation() + player.getWidth() > SCREEN_WIDTH ) || checkCollision( temp, wall ) )
    {
        //Move back
        player.setLocationX( player.getXLocation() - player.getVelX());
        temp.x = player.getXLocation();
    }

    //Move the dot up or down
    player.setLocationY(player.getYLocation() + player.getVelY() );
    temp.y = player.getYLocation();
    //If the dot collided or went too far up or down
    if( ( player.getYLocation() < 0 ) || ( player.getYLocation() + player.getHeight() > SCREEN_HEIGHT ) || checkCollision( temp, wall ) )
    {
        //Move back
        player.setLocationY( player.getYLocation() - player.getVelY());
        temp.y = player.getYLocation();
    }

}

Terrain Level::getTerrain(){
    return terrain;
}

Player& Level::getUser(){
    return user;
}