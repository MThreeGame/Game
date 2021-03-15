/* File that handle all the SDL part */
// following the tutorial from https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php


//Include SDL functions and datatypes
#include "SDL.h"
#include <string>
#include "KeyPressSurface.h"
#include "Character.h"
#include "Player.h"

using namespace std;


class SDL_game{
    public:
        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia();

        //Frees media and shuts down SDL
        void close();

        // blit the background
        //void blitSurface();


        void handleKeys_fct();

        void render();

        void handleEvent( SDL_Event& e );



    private:
        // ATTRIBUTES
        // size of the window
        int SCREEN_WIDTH = 850;
        int SCREEN_HEIGHT = 500;

        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;
            
        //The surface contained by the window
        SDL_Surface* gScreenSurface = NULL;

        //The images we will load and show on the screen
        //SDL_Surface* gBackground = NULL;
        //The window renderer
        SDL_Renderer* gRenderer = NULL;




        //Current displayed image
        SDL_Surface* gCurrentSurface = NULL;

        //The images that correspond to a keypress
        SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];


        // other present objects
        Character* user = new Player();
        SDL_Texture* gUser = NULL;


        // METHODES
        //Loads individual image
        SDL_Surface* loadSurface(string path);

        // TODO : change with the class of Hugo
        SDL_Texture* loadTexture( std::string path );

};



