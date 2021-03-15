#include "LTexture.h"
#include <SDL_image.h>
# include <iostream>

using namespace std;


LTexture::LTexture(const char *filename,
                            SDL_Renderer* renderer){
	//LTexture *lTexture;
    //lTexture = new (LTexture);
    this->scale = 1.0;
	this->texture = NULL;
	this->renderer = renderer;
    SDL_Surface* loadedSurface = SDL_LoadBMP( filename );
	//SDL_Surface *loadedSurface = IMG_Load(filename);
	if (loadedSurface == NULL) {
        cout << "Unable to load image from " << filename << endl;
	} else {
        this->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (this->texture == NULL) {
            cout << "Unable to create texture from " << filename << endl;
        }
        SDL_FreeSurface(loadedSurface);
	}
    //return lTexture;
}

/*
void LTexture::LTexture__delete(LTexture *lTexture) {
    SDL_DestroyTexture(lTexture->texture);
    delete(lTexture);
}*/

void LTexture::LTexture_render(int x, int y) {

    SDL_Rect dstrect = {x, y, mWidth, mHeight};
	SDL_RenderCopy(renderer, texture, &dstrect, &dstrect);
}
