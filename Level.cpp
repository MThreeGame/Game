#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"

//Cell of the vector returned downside, upside , rightside, leftside
vector<Cell> Level::checkCollisions(){
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
            if (ground[i][newLocY] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (ground[i][newLocY] == Cell::DANGER) {
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
            if (ground[i][newLocY] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (ground[i][newLocY] == Cell::DANGER) {
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
            if (ground[newLocX][i] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (ground[newLocX][i] == Cell::DANGER) {
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
            if (ground[newLocX][i] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (ground[newLocX][i] == Cell::DANGER) {
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
   vector<Cell> cells = checkCollisions();
   int Xloc = user.getXLocation();
   int Yloc = user.getYLocation();
   int newLocX = user.getXLocation()+ user.getVelX();
   int newLocY = user.getXLocation()+ user.getVelY();

/*
    int DOWN = 0, UP = 1 , RIGHT = 2, LEFT = 3;
    // check for the Y axis
    if(cells[DOWN] == Cell::DANGER || cells[UP] == cell::DANGER){
        // we put the user at the original position, in the upper left corner
        user.setLocationX(0);
        user.setLocationY(0);
        user.setNumLife(user.getNumLife() - 1); // the last time, David said it is better to have a decreaseLife function
    }else{
        //user.move();
        if(cells.at(0) == Cell::BACKGROUND){
            user.setLocationY(newLocY);
        }
    }

    same thing for X axis.


    I think it is better:
    * check if Danger somewhere in cells, 
    * if yes -> set position of the user at 0,0 and decrease life
    * else, for Y axis then X axis, modify set velY ot velX to 0 if GROUND
    * then user.move()




*/

   if(user.getVelY() > 0){
       if(cells.at(0) == Cell::DANGER){
           user.setLocationX(0);
           user.setLocationY(0);
           user.setNumLife(user.getNumLife() - 1);
       }else{
           user.move();
           if(cells.at(0) == Cell::GROUND){
               user.setLocationY(Yloc);
           }
       }
   }else if(user.getVelY() < 0){
       if(cells.at(1) == Cell::DANGER){
           user.setLocationX(0);
           user.setLocationY(0);
           user.setNumLife(user.getNumLife() - 1);
       }else{
           //user.move();
           if(cells.at(1) == Cell::GROUND){
               user.setLocationY(Yloc);
           }
       }
   }
    if(user.getVelX() > 0){
       if(cells.at(2) == Cell::DANGER){
           user.setLocationX(0);
           user.setLocationY(0);
           user.setNumLife(user.getNumLife() - 1);
       }else{
           user.move();
           if(cells.at(2) == Cell::GROUND){
               user.setLocationX(Xloc);
           }
       }
   }else if(user.getVelX() < 0){
       if(cells.at(3) == Cell::DANGER){
           user.setLocationX(Xloc);
           user.setLocationY(Yloc);
           user.setNumLife(user.getNumLife() - 1);
       }else{
           user.move();
           if(cells.at(3) == Cell::GROUND){
               user.setLocationX(Xloc);
           }
       }
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


Terrain Level::getTerrain(){
    return terrain;
}

Player& Level::getUser(){
    return user;
}