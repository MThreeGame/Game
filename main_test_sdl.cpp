#include "SDL_game.h"

// https://lazyfoo.net/tutorials/SDL/index.php




int SDL_game::SCREEN_WIDTH = 1366;
int SDL_game::SCREEN_HEIGHT = 768;


int main(int argc, char* args[] ){

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
}





