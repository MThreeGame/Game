#include "SDL_game.h"
#include <string>

using namespace std;



bool SDL_game::init()
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
        gWindow = SDL_CreateWindow( "Adventure Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}


bool SDL_game::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load background image
    gBackground = loadSurface("../images/ground1.bmp" );
    if(gBackground == NULL)
        return false;

    gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN] = loadSurface("../images/user1.bmp" );
    if(gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN] == NULL)
        return false;

    gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_UP] = loadSurface("../images/monster.bmp" );
    if(gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_UP] == NULL)
        return false;  

    return true;
}

void SDL_game::close()
{
    //Deallocate surface
    SDL_FreeSurface( gBackground );
    gBackground = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

// Blit the image
void SDL_game::blitSurface(){
    //Apply the image
    SDL_BlitSurface( gBackground, NULL, gScreenSurface, NULL );

    //Update the surface
    SDL_UpdateWindowSurface( gWindow );

    //Wait two seconds
    SDL_Delay( 2000 );
}


SDL_Surface* SDL_game::loadSurface( std::string path )
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return NULL;
    }

    return loadedSurface;
}

void SDL_game::handleKeys_fct(){
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Set default current surface
    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                        break;

                    case SDLK_DOWN:
                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                        break;

                    /*case SDLK_LEFT:
                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                        break;

                    case SDLK_RIGHT:
                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                        break;
                    */

                    default:
                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                        break;
                }
            }
        }

        //Apply the current image
        SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
            
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }
}

