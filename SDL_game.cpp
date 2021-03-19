#include "SDL_game.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//opens a window of the defined size
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
    //load user
    gUser = loadTexture( level.getUser().getPath());
    if(gUser == NULL)
        return false;
    //load background
    gBackground = loadTexture(level.getTerrain().getPathToImage());
    if(gBackground == NULL)
        return false;
    //load hearts
    gLife = loadTexture("../images/heart.bmp");
    if(gLife == NULL)
        return false;
    //load stars
    if(level.getStar().empty())
        cout << "There is no star to initialise" << endl;
    else{
        gStar = loadTexture(level.getStar()[0]->getPath());
        if(gStar == NULL)
            return false;
    }
    //load monsters
    if(level.getMonsters().empty())
        cout << "There is no monster to initialise" << endl;
    else
        gMonster = loadTexture(level.getMonsters()[0]->getPath());

    return true;
}
//close the window
void SDL_game::close()
{
    //Deallocate textures
    SDL_DestroyTexture( gUser );
    gUser = NULL;
    SDL_DestroyTexture( gBackground );
    gBackground = NULL;
    SDL_DestroyTexture( gLife );
    gLife = NULL;
    SDL_DestroyTexture( gStar );
    gStar = NULL;
    SDL_DestroyTexture( gMonster );
    gMonster = NULL;

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

//handles the key that is pressed
int SDL_game::handleKeys_fct(){
    //Main loop flag
    bool quit = false;
    //Event handler
    SDL_Event e;
    unsigned int lastTime = 0;
    unsigned int currentTime;
    double mass = 0;
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
        //move the different objects required
        // move the player:
        level.moveWithCollision2();
        level.collisionWithStar();
        // move the monsters:
        level.moveMonsters();
        //lets check if the user has win or lose
        if(level.getUser().getNumLife() <= 0) // the user lost
            return 0;
        if(level.getStar().empty())
            return 1;
        //Clear screen
        //SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        //Render texture to screen
        render();
        //Update screen
        SDL_RenderPresent( gRenderer );
        currentTime = SDL_GetTicks();
        cout << level.getUser().getVelY() << endl;
        currentTime = SDL_GetTicks();
        cout << level.getUser().getVelY() << endl;
        if(level.getUser().getVelY() > 0 && level.getUser().getFlagY()){//(level.getUser().getVelY() < 1){
            level.getUser().setVelY(1);
            mass = 0.005;
        }else{
            mass += 0.002;
            if (currentTime > lastTime + 80) {
                lastTime = currentTime;
                level.getUser().setVelY(level.getUser().getVelY() + 0.6 + mass);
            }
        }
    }
    // here the user has quit
    return -1;
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
            cout << "DOWN" << level.getUser().getVelY() << endl;
                if(level.getUser().getVelY() > 0 && level.getUser().getFlagY()){
                    level.getUser().decreaseVelY();
                    level.getUser().decreaseVelY();
                }
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
                ////////////////////RIEN    
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
	SDL_Rect dstrect = {(int) level.getUser().getXLocation(),(int) level.getUser().getYLocation(), level.getUser().getWidth(), level.getUser().getHeight()};
    SDL_RenderCopy(gRenderer, gBackground, NULL, NULL);
    SDL_RenderCopy(gRenderer, gUser, NULL, &dstrect);
    for(int i = 0; i < level.getUser().getNumLife(); i++)
        SDL_RenderCopy(gRenderer, gLife, NULL, &lifePosition[i]);

    vector<Star*> stars = level.getStar();
    for(int i = 0; i < stars.size(); i++){
        SDL_Rect starRect = stars[i]->getRect();
            SDL_RenderCopy(gRenderer, gStar, NULL, &starRect);

    }
    vector<Monster*> monsters = level.getMonsters();
    for(int i = 0; i < monsters.size(); i++){
        SDL_Rect monsterRect = (monsters[i]->getRect());
        SDL_RenderCopy(gRenderer, gMonster, NULL, &monsterRect);
    }
}

//loads the image on window
SDL_Texture* SDL_game::loadTexture(string path )
{   //The final texture
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

Level SDL_game::getLevel(){
    return level;}