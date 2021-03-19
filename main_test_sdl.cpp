#include "winWindow.h"
#include "SDL_game.h"
#include <iostream>

using namespace std;

// https://lazyfoo.net/tutorials/SDL/index.php




int main(int argc, char* args[] ){
    cout<<"hbhbh"<<endl;
    winWindow windowWin;
    SDL_game sdlGame;

    // Print a report once per second
  
    if( ! sdlGame.init())
    {
        printf( "Failed to initialize SDL!\n" );
    }
    else {
        //Load media

        if (!sdlGame.loadMedia()) {
            printf("Failed to load media!\n");
        }
        else {
            //Apply the image
            //sdlGame.blitSurface();
            cout << "hey" << endl;
            sdlGame.handleKeys_fct();

        }
    }
    // show winner window
    //Wait two seconds
    //SDL_Delay( 6000 );
    if( ! windowWin.init()) {
            printf( "Failed to initialize SDL!\n" );
    }
    else {  //Load media
            if (!windowWin.loadMedia()) {
                printf("Failed to load media!\n");
            }
            else {
                windowWin.runWindow();
            }

        }
            //Wait six seconds
            SDL_Delay( 10000 );
          //Free resources and close SDL
            sdlGame.close();
            windowWin.close();
    return 0;
}





