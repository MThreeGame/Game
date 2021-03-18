#pragma once 

#include "SDL.h"
#include <string>

using namespace std;


class LTexture {
    public:

        LTexture();
    
        void initLTexture(string path, int posX, int posY, int widthImage, int heightImage, SDL_Renderer* rend);

        SDL_Rect createRect();

        bool loadImage();

        void render();

        string getPath();

        SDL_Texture* loadTexture(string path);

        void renderLTexture();

        void setPath(string pathIn);

        int getPosImageX();
        int getPosImageY();
        int getWidth();
        int getHeight();



    private:

        int SCREEN_WIDTH = 1366;
        int SCREEN_HEIGHT = 768;

        int posImageX = 0;
        int posImageY = 0;
        int width = 0;
        int height = 0;

        string path;

        SDL_Rect rect;


        // The graphical representation of the Terrain
        SDL_Texture* image = NULL;
        SDL_Renderer* renderer;

        //change with the class LTexture to have some animations



};
