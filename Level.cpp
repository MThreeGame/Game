#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"

//Cell of the vextor returned downside, upside , rightside, leftside
vector<Cell> Level::checkCollisions( Player player){
   vector<Cell> checkResult;
   int Xloc = player.getXLocation();
   int Yloc = player.getYLocation();
   int newLocX = player.getXLocation()+ player.getVelX();
   int newLocY = player.getXLocation()+ player.getVelY();
   Cell flag = Cell::BACKGROUND;
   int height = player.getHeight();
   int width = player.getWidth();
   if( player.getVelY() > 0 ) {
        //checking downside
        for (int i = Xloc; i <= (Xloc + width); i++) {
            if (terrain.getGround()[i][newLocY] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (terrain.getGround()[i][newLocY] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
        flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }
    if(player.getVelY() < 0){
        // checking upside
        for (int i = newLocX ; i >= (newLocX + width); i++) {
            if (terrain.getGround()[i][newLocY] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (terrain.getGround()[i][newLocY] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
       flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }

    if( player.getVelX() > 0 ) {
        //checking rightside
        for (int i = Yloc; i <= (Yloc + height); i++) {
            if (terrain.getGround()[newLocX][i] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (terrain.getGround()[newLocX][i] == Cell::DANGER) {
                flag = Cell::DANGER;
                break;
            }
        }
        checkResult.push_back(flag);
        flag = Cell::BACKGROUND;
    }else{
        checkResult.push_back(flag);
    }
    if(player.getVelX() < 0){
        // checking leftside
        for (int i = (Yloc - height); i >= Yloc; i--) {
            if (terrain.getGround()[newLocX][i] == Cell::GROUND) {
                flag = Cell::GROUND;
                break;
            }
            if (terrain.getGround()[newLocX][i] == Cell::DANGER) {
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

void moveWithCollision(vector<Cell> cells){
   int Xloc = user.getXLocation();
   int Yloc = user.getYLocation();
   int newLocX = user.getXLocation()+ user.getVelX();
   int newLocY = user.getXLocation()+ user.getVelY();

   if(user.getVelY > 0){
       if(cells.at(0) == Cell::DANGER){
           user.setLocationX(Xloc);
           user.setLocationY(Yloc);
           user.setNumLife = user.getNumLife() - 1;
       }else{
           user.move();
           if(cells.at(0) == Cell::GROUND){
               user.setLocationY(Yloc);
           }
       }
   }else if(user.getVelY > 0){
       if(cells.at(1) == Cell::DANGER){
           user.setLocationX(Xloc);
           user.setLocationY(Yloc);
           user.setNumLife = user.getNumLife() - 1;
       }else{
           user.move();
           if(cells.at(1) == Cell::GROUND){
               user.setLocationY(Yloc);
           }
       }
   }
    if(user.getVelX > 0){
       if(cells.at(2) == Cell::DANGER){
           user.setLocationX(Xloc);
           user.setLocationY(Yloc);
           user.setNumLife = user.getNumLife() - 1;
       }else{
           user.move();
           if(cells.at(2) == Cell::GROUND){
               user.setLocationX(Xloc);
           }
       }
   }else if(user.getVelX < 0){
       if(cells.at(3) == Cell::DANGER){
           user.setLocationX(Xloc);
           user.setLocationY(Yloc);
           user.setNumLife = user.getNumLife() - 1;
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