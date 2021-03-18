#include "LTexture.h"
#include <SDL_image.h>
# include <iostream>

using namespace std;

LTexture::LTexture(){}

void LTexture::initLTexture(string path, int posX, int posY, int widthImage, int heightImage, SDL_Renderer* rend){
    posImageX = posX;
    posImageY = posY;
    width = widthImage;
    height = heightImage;
    renderer = rend;
    image = loadTexture(path);

    /*
    rect.x = posX;
    rect.y = posY;
    rect.w = widthImage;
    rect.h = heightImage;
    SDL_Rect rect2 = {posX, posY, widthImage, heightImage};
    rect = rect2;*/

}

SDL_Rect LTexture::createRect(){
    SDL_Rect rect2 = {this->getPosImageX(), this->getPosImageY(), this->getWidth(), this->getHeight()};
    return rect2;
}


bool LTexture::loadImage()
{

    image = loadTexture(path);
    if(image == NULL){
        return false;
    }
    return true;
}



SDL_Texture* LTexture::loadTexture(string path)
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

void LTexture::renderLTexture(){
    std::cout << "Renderer could not be rggdfgdfgreg333sdasda" << std::endl;
    //SDL_Rect dstrect = this->createRect();

    std::cout << posImageX << std::endl;
    std::cout << this->getPosImageY() << std::endl;
    std::cout << this->getWidth() << std::endl;
    SDL_Rect dstrect = {this->getPosImageX(), this->getPosImageY(), this->getWidth(), this->getHeight()};

      std::cout << "5555555555555555555555           dasda" << std::endl;
    if(image == NULL){
        std::cout << "5555555555555555555555" << std::endl;
    }
    if(renderer == NULL){
        std::cout << "666666666666666666666666" << std::endl;
    }
    SDL_RenderCopy(renderer, image, NULL, NULL);
        std::cout << "Rendfgdfgreg5555555555" << std::endl;

}


string LTexture::getPath(){
    return path;
}

int LTexture::getPosImageX(){
    return posImageX;
}

int LTexture::getPosImageY(){
    return posImageY;
}

int LTexture::getWidth(){
    return width;
}

int LTexture::getHeight(){
    return height;
}




void LTexture::setPath(string pathIn){
    path = pathIn;
}
