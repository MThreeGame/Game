#pragma once

#include "SDL.h"
#include "constants.h"
#include "LTexture.h"

enum MenuChoice {
    MENU_NONE, // User has not made a choice
    MENU_QUIT, // User wishes to quit
    MENU_PLAY  // User wishes to play
};

class Menu {
    private:
        enum MenuChoice choice;         // The choice of the user    
        LTexture backGround; // The back ground LTexture
        
        /*LTexture title;      // The title LTexture
        LTexture play;       // The play LTexture
        LTexture quit;       // The quit LTexture*/
        SDL_Renderer *renderer;         // The renderer
    public:

        Menu();
    

        void initMenu(SDL_Renderer *renderer);

        
        //Start running the menu.
        void runMenu();

};
