#include "Menu.h"
#include "SDL.h"

void Menu::initMenu(SDL_Renderer *renderer) {
    this->renderer = renderer;
    choice = MenuChoice::MENU_NONE;
    backGround.initLTexture("../images/ground1.bmp", renderer, 10, 10);

}

void Menu::runMenu(){
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);
        backGround.renderLTexture (50, 50);
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    SDL_Event e;
    choice = MENU_NONE;
    while (choice == MenuChoice::MENU_NONE) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                choice = MENU_QUIT;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_1:
                        choice = MENU_PLAY;
                        break;
                    case SDLK_2:
                        choice = MENU_QUIT;
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);
        backGround.renderLTexture (50, 50);
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    }
}

