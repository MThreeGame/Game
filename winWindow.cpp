//
// Created by admin on 2021-03-18.
//
#include "winWindow.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool winWindow::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Result", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

            }

        }
    }

    return success;
}

void winWindow::close()
{
    //Destroy window
    SDL_DestroyTexture( finalBackground );
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void winWindow::render()
{
    SDL_RenderCopy(gRenderer, finalBackground, NULL, NULL);

}

bool winWindow::loadMedia(){
    finalBackground = loadTexture("../images/win.bmp");
    if(finalBackground == NULL)
        return false;
    else return true;
}
SDL_Texture* winWindow::loadTexture(string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    //SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error\n", path.c_str() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

void winWindow::runWindow(int res){
    //SDL_RenderClear( gRenderer );
    //Render texture to screen
    render();
    //Update screen
    SDL_RenderPresent( gRenderer );

    //Event handler
    SDL_Event e;
    bool quit = false;
    while( !quit )
    {
        cout << "HEy" << endl;
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_WINDOWEVENT
        && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                cout << "I quit" << endl;
                quit = true;
            }
        }
        cout << "bouh:P" << endl;
    }

}



