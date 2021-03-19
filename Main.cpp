#include "winWindow.h"
#include "SDL_game.h"
#include <iostream>

using namespace std;

// https://lazyfoo.net/tutorials/SDL/index.php




int main(int argc, char* args[] ){
    cout<<"hbhbh"<<endl;
    SDL_game sdlGame;
    int returnFct = -1;

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
            returnFct = sdlGame.handleKeys_fct();

        }
    }

    cout << "return value: " << returnFct;

    if(returnFct == -1){ // he user quit or something goes wrong
        sdlGame.close();
        return 0;
    }


    // show winner window
    //Wait two seconds
    //SDL_Delay( 6000 );
    winWindow windowWin;

    if( ! windowWin.init()) {
            printf( "Failed to initialize SDL!\n" );
    }
    else {  //Load media
            if (!windowWin.loadMedia()) {
                printf("Failed to load media!\n");
            }
            else {
                windowWin.runWindow(returnFct);
            }

        }
            //Wait six seconds
            //SDL_Delay( 10000 );
          //Free resources and close SDL
            windowWin.close();
            sdlGame.close();

    return 0;
}





