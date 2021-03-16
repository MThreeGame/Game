#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"


string Level::checkCollisions( Player player){

   string ground = "GROUND";
   string monster = "MONSTER";
   string safeMode = "SAFE";
   int newLocationX = player.getXLocation()+ player.getVelX();
   int newlocationY = player.getYLocation() + player.getVelY();
    bool groundFlag = false;
    bool monsterFlag = false;
    int height = player.getHeight();
    int width = player.getWidth();
    for(int j = newlocationY; j <=  (newlocationY+ height); j++) {
        if(groundFlag || monsterFlag) break;
        for(int i = newLocationX; i <=  (newLocationX + width); i++) {

            if ( terrain.getGround()[i][j] == Cell::GROUND) {
                groundFlag = true;
                break;
            }
            if (terrain.getGround()[i][j] == Cell::DANGER) {
                monsterFlag = true;
                break;
            }
        }
    }
    if(groundFlag) return ground;
    else if(monsterFlag) return monster;
    else return safeMode;
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

Player Level::getUser(){
    return user;
}