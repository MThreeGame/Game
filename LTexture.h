#pragma once

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class LTexture {
    private:
        int mWidth;
        int mHeight;
        float scale;            // The scale of the rendered sprite
        SDL_Texture *texture;   // The texture (image) of the sprite sheet
        SDL_Renderer *renderer; // The renderer
        string filename;
    public:

        /**
        * Creates a LTexture.
        *
        * @param filename    The filename of the sprite sheet image
        * @param renderer    The renderer used for loading the sprite sheet
        * @return            The LTexture
        */
        void initLTexture (const char* filename, SDL_Renderer* renderer, int mWidthIn, int mHeightIn);




        /**
        * Delete the LTexture.
        *
        * @param lTexture  The Texture to delete
        */
        void deleteLTexture();

        /**
        * Renders the LTexture.
        *
        * @param lTexture  The LTexture to render
        * @param x            The top-left corner x-coordinate for the render
        * @param y            The top-left corner y-coordinate for the render
        */
        void renderLTexture(int x, int y);
};

