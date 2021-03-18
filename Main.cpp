
#include <stdio.h>
#include <SDL.h>
#include "SDL_game.h"
// must take the argument SDL as a reference maybe
int displayMenu(){
    // dissplay the menu
    // wait the user answer

    // return the valid answer
    return 0;
}
/*
void displayTerrain(Level &level, Player &player){
  // SDL part
} */


int main( int argc, char* args[] ){


    SDL_game sdlGame;
    if( ! sdlGame.init())
    {
        printf( "Failed to initialize SDL!\n" );
    }
    else
    {
        //Load media
        if( ! sdlGame.loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            //sdlGame.blitSurface();

            sdlGame.handleKeys_fct();

        }
    }

    //Free resources and close SDL
    sdlGame.close();

    return 0;

    //Player player;

    // Level level; // must initialize the monster list, and the star list

    // SDL create window,
    //displayMenu();


    //displayTerrain(level, player);

    /*bool flag = false; // TODO

    while(!flag){

        *//*
          Player can move

        // to think: to follow the player, or change the background when the player go out of                                 bound
    update_sdl()
    update_environment()
    update_sdl()
    *//*

    flag = true;

  }
*/


}