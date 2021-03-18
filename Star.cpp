#include "Star.h"


/*

Star::Star(int x, int y, int heightIn, int widthIn){
  locationX = x;
  locationY = y;
  height = heightIn;
  width = widthIn;
  velX = 0;
  velY = 0;
}
*/

string Star::getPath(){
    return pathToImage;
}

int Star::getNumStar(){
    return numStar;
}

int Star::getNumCatched(){
    return numCatched;
}

vector <bool> Star::getStarCatched(){
    return starCatched;
}

SDL_Texture* Star::getGStar(){
    return gStar;
}

vector<SDL_Rect> Star::getStarPosition(){
    return starPosition;
}

bool Star::win(){
    int count = 0;
    for (bool b : starCatched){
        if(!b){
            count++;
        }
    }
    return count == numStar;
}

void Star::setStarCatched(int index){
    starCatched[index] = false;
}