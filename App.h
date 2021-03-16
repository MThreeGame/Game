#pragma once

#include "SDL.h"
#include "Menu.h"


enum AppState {
    APP_STATE_MENU,  // We show the menu
    APP_STATE_PLAY,  // We are playing
    APP_STATE_QUIT,  // We are quitting
    APP_STATE_WIN    // We show the win screen
};

class App {
    private:
        enum AppState state;        // The current state
        SDL_Window* window;         // The window
        SDL_Renderer* renderer;     // The renderer
        bool error;                 // If the app was loaded succesfuly
        Menu menu;                  // The menu

    public:
        //Constructor
        App();


        //Start running the application.
        void appRun();


        //Deletes the given application.
        void appDelete();
};
