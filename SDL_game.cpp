#include "SDL_game.h"
#include <string>
//#include "LTexture.h"
#include <iostream>

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

                // TODO for png file. For now we only handle bmp file
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

// load the different textures needed
bool SDL_game::loadMedia()
{
    //Loading success flag
    bool success = true;

    gUser = loadTexture( level.getUser().getPath());
    if(gUser == NULL)
        return false;

    gBackground = loadTexture(level.getTerrain().getPathToImage());
    if(gBackground == NULL)
        return false;


/*
    for(SDL_Rect& rect : level.getTerrain().getGrounds()){
        SDL_SetRenderDrawColor(gRenderer,255, 0, 0, 255);
        SDL_RenderDrawRect(gRenderer, &rect);

        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

        SDL_RenderPresent(gRenderer);
    }
*/

    return true;
}

void SDL_game::close()
{
    //Deallocate textures
    SDL_DestroyTexture( gUser );
    gUser = NULL;

    SDL_DestroyTexture( gBackground );
    gUser = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

// not used anymore
SDL_Surface* SDL_game::loadSurface( std::string path )
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error\n", path.c_str() );
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
            //Handle input for the character user
            handleEvent(e );
        }

        //level.getUser().move();
        level.moveWithCollision2();

        //Clear screen
        //SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render texture to screen
        render();
        
        //Update screen
        SDL_RenderPresent( gRenderer );
    }
}


// for a specific keyboard event, modify the object Player
void SDL_game::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
                level.getUser().decreaseVelY(); 
                break;
            case SDLK_DOWN: 
                level.getUser().increaseVelY(); 
                break;
            case SDLK_LEFT: 
                level.getUser().decreaseVelX(); 
                break;
            case SDLK_RIGHT:
                level.getUser().increaseVelX(); 
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
                level.getUser().increaseVelY(); 
                break;
            case SDLK_DOWN: 
                level.getUser().decreaseVelY();  
                break;
            case SDLK_LEFT: 
                level.getUser().increaseVelX();
                break;
            case SDLK_RIGHT:
                level.getUser().decreaseVelX(); 
                break;
        }
    }
}


void SDL_game::render()
{
    //Show the character (user)
    //gUser->render(user->getLocationX(), user->getLocationY());
    //cout << "I am in render function" << endl;
    //gUser->LTexture_render(user->getLocationX(), user->getLocationY());
	SDL_Rect dstrect = {level.getUser().getLocationX(), level.getUser().getLocationY(), 50, 100};
    SDL_RenderCopy(gRenderer, gBackground, NULL, NULL);
    SDL_RenderCopy(gRenderer, gUser, NULL, &dstrect);


    /*
    for(SDL_Rect& rect : level.getTerrain().getGrounds()){
        SDL_SetRenderDrawColor(gRenderer,255, 0, 0, 255);
        SDL_RenderDrawRect(gRenderer, &rect);

        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

        SDL_RenderPresent(gRenderer);
    }*/


}


SDL_Texture* SDL_game::loadTexture(string path )
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