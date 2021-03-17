#include "LTexture.h"
#include <SDL_image.h>
# include <iostream>

using namespace std;


LTexture::LTexture()(sting path){
    this->path = path;
}


bool LTexture::loadImage)
{

    image = loadTexture(path.c_str());
    if(image == NULL)
        return false;

    return true;
}



SDL_Texture* LTexture::loadTexture()
{

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    //SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        cout << "Unable to load image " << path << "! SDL Error" << endl;
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            cout << "Unable to create texture from " << path << "! SDL Error" << endl;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}