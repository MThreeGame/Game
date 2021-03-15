#include "LTexture.h"

using namespace std;


LTexture *LTexture_create(const char *filename,
                            SDL_Renderer* renderer){
	LTexture *lTexture;
    lTexture = new (LTexture);
    lTexture->scale = 1.0;
	lTexture->texture = NULL;
	lTexture->renderer = renderer;
	SDL_Surface *loadedSurface = IMG_Load(filename);
	if (loadedSurface == NULL) {
        cout << "Unable to load image from " << filename << ": " << IMG_GetError() << endl;
	} else {
        lTexture->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (lTexture->texture == NULL) {
            cout << "Unable to create texture from " << filename << ": " << SDL_GetError() << endl;
        }
        SDL_FreeSurface(loadedSurface);
	}
    return lTexture;
}

void LTexture__delete(LTexture *lTexture) {
    SDL_DestroyTexture(lTexture->texture);
    delete(lTexture);
}

void LTexture_render(LTexture *lTexture,
                        int x, int y) {

    SDL_Rect dstrect = {x, y, mWidth, mHeight);
	SDL_RenderCopy(lTexture->renderer, lTexture->texture, &dstrect, &dstrect);
}
