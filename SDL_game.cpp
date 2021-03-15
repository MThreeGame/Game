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
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
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

                //Initialize PNG loading
                /*
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                */
            }
            
        }
    }

    return success;
}


bool SDL_game::loadMedia()
{
    //Loading success flag
    bool success = true;

    
    //Load background image
    /*gBackground = loadSurface("../images/ground1.bmp" );
    if(gBackground == NULL)
        return false;
    */


    //gUser = loadSurface(user.getPath() )
    gUser = loadTexture( user->getPath().c_str());

/*
    gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN] = loadSurface("../images/user1.bmp" );
    if(gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_DOWN] == NULL)
        return false;

    gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_UP] = loadSurface("../images/monster.bmp" );
    if(gKeyPressSurfaces[KeyPressSurfaces::KEY_PRESS_SURFACE_UP] == NULL)
        return false;  
    */

    return true;
}

void SDL_game::close()
{
    //Deallocate surface
    //SDL_FreeSurface( gBackground );
    //gBackground = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

/*
// Blit the image
void SDL_game::blitSurface(){
    //Apply the image
    SDL_BlitSurface( gBackground, NULL, gScreenSurface, NULL );

    //Update the surface
    SDL_UpdateWindowSurface( gWindow );

    //Wait two seconds
    SDL_Delay( 2000 );
}
*/

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
            ////Handle input for the character user
            //handleEvent( SDL_Event& e );
        }

        user->move();

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render objects
        render();

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
}



void SDL_game::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
                user->decreaseVelY(); 
                break;
            case SDLK_DOWN: 
                user->increaseVelY(); 
                break;
            case SDLK_LEFT: 
                user->decreaseVelX(); 
                break;
            case SDLK_RIGHT:
                user->increaseVelX(); 
                break;
        }
    }

    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
                user->increaseVelY(); 
                break;
            case SDLK_DOWN: 
                user->decreaseVelY(); 
                break;
            case SDLK_LEFT: 
                user->increaseVelX(); 
                break;
            case SDLK_RIGHT:
                user->decreaseVelX(); 
                break;
        }
    }
}


void SDL_game::render()
{
    //Show the character (user)
    gUser->render(user->getLocationX(), user->getLocationY());
}


SDL_Texture* SDL_game::loadTexture( std::string path )
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