#include "Level.h"
#include "SDL.h"
#include "Player.h"
#include "Cell.h"


vector<Cell> Level::checkCollisions( Player player){
   vector<Cell> checkResult;
   int Xloc = player.getXLocation();
   int Yloc = player.getYLocation();
   int newLocX = player.getXLocation()+ player.getVelX();
   int newLocY = player.getXLocation()+ player.getVelY();
   Cell flag;
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
   }
   else if(player.getVelY() < 0){
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
   }

    if( player.getVelX() > 0 ) {
        //checking rightside
        for (int i = newLocY; i <= (newLocY + height); i++) {
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
    }
    else if(player.getVelX() < 0){
        // checking leftside
        for (int i = (newLocY - height); i >= newLocY; i--) {
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
    }
    return checkResult;


    /*
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
     */

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