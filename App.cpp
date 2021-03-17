#include <iostream>
#include <SDL_image.h>
#include "constants.h"
#include "App.h"

using namespace std;

 App::App() {
    error = false;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

        cout << "SDL failed to initialize" << endl;
        error = true;
    }
    /*
    if (TTF_Init() == -1 && !(error)) {
        cout << "TTF can not be initialized" << endl;
        error = true;
    }
    */
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        cout << "Warning: Linear texture filtering not enabled!" << endl;
    }
    window = SDL_CreateWindow("name of game",
                                   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        cout << "Window could not be created" << endl;
    }
    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        cout << "Renderer could not be created" << endl;
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    Menu menu;
    menu.initMenu(renderer);

    
    ////////////////////////////////////////////menu.initMenu(renderer);

    /*
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image failed to initialize" << endl;
    }*/

    state = AppState::APP_STATE_MENU;
}

void App::appRun(){
    while (state != AppState::APP_STATE_QUIT) {
        SDL_SetWindowSize(window, SCREEN_WIDTH, SCREEN_HEIGHT);
        switch (state) {
            case APP_STATE_MENU:
                cout << "HERE IS MENU" << endl;
                menu.runMenu();
                state = AppState::APP_STATE_QUIT;
   
                break;
            case APP_STATE_PLAY:

                break;
            case APP_STATE_WIN:

                break;
            case APP_STATE_QUIT:
                break;
        }
    }
}

void App::appDelete() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

