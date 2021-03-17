#pragma once 

#include "SDL.h"
#include <string>

using namespace std;


class LTexture {
    public:
        LTexture(string path);

        bool loadMedia();

        void render();

        string getPath();


    private:

        int SCREEN_WIDTH = 1366;
        int SCREEN_HEIGHT = 768;

        int posImageX;
        int posImageY;
        int width;
        int height;

        string path;


        // The graphical representation of the Terrain
        SDL_Texture* image = NULL;
        SDL_Renderer* renderer;

        //change with the class LTexture to have some animations
        SDL_Texture* loadTexture(std::string path);

        void renderLTexture(){
            SDL_Rect dstrect = { posImageX, posImageY, width, height};
            SDL_RenderCopy(renderer, image, NULL, &dstrect);
        }


};
