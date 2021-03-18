#include "Menu.h"
#include "SDL.h"

#include <iostream>

/*Menu::Menu(string path){
    backGround(path);
}*/

void Menu::initMenu(SDL_Renderer *renderer) {
    this->renderer = renderer;
    choice = MenuChoice::MENU_NONE;
    backGround = new (LTexture);
    //backGround->setPath("../images/monster.bmp");
    backGround->initLTexture("../images/monster.bmp", 50, 50, 50, 50, renderer);
}

void Menu::runMenu(){

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);
        std::cout << "Renderer could not be rggdfgdfgreg" << std::endl;

        backGround->renderLTexture();
        std::cout << "Renderer could not be rggdfgdfgreg" << std::endl;
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
        backGround->renderLTexture();
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    }
}

