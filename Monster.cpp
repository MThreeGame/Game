#include "Monster.h"
#include <random>


Monster::Monster(string path):Character(){
    pathToImage = path;
    // lets use a random position for the X between 200 and 1366;
    // 200 is to be far enought of the player who is initialised to the position (0,0)
    // 1366 is the length of the background
    int min = 200 ;
    int max = 1366 ;

    locationX = min + ( std::rand() % ( max - min + 1 ) );
    locationY = 0;

    height = 50;
    width = 50;

    // lets add a gravity
    velY = 1;

}


