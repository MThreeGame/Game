#include "LTexture.h"
#include <SDL_image.h>
# include <iostream>

using namespace std;


void LTexture::initLTexture(const char* filename,
                            SDL_Renderer* renderer, int mWidthIn, int mHeightIn){
    mWidth = mWidthIn;
    mHeight = mHeightIn;
    scale = 1.0;
	texture = NULL;
	renderer = renderer;
	SDL_Surface *loadedSurface = SDL_LoadBMP(filename);
	if (loadedSurface == NULL) {
        cout << "Unable to load image from " << filename << endl;
	} else {
        this->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (this->texture == NULL) {
            cout << "Unable to create texture from " << filename << endl;
        }
        SDL_FreeSurface(loadedSurface);
	}
}

void LTexture::deleteLTexture() {
    SDL_DestroyTexture(texture);
    //delete(lTexture);
}

void LTexture::renderLTexture( int x, int y) {

    SDL_Rect dstrect = {x, y, mWidth, mHeight};
    SDL_RenderCopy(renderer, texture, &dstrect, &dstrect);
}
