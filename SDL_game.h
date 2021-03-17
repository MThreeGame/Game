/* File that handle all the SDL part */
// following the tutorial from https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php


//Include SDL functions and datatypes
#include "SDL.h"
#include <string>
#include "KeyPressSurface.h"
#include "Character.h"
#include "Player.h"
//#include "LTexture.h"
#include "Level.h"

using namespace std;


class SDL_game{
    public:
        SDL_game(){}

        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia();

        //Frees media and shuts down SDL
        void close();

        // blit the background
        //void blitSurface();

        //main function where we handle the keyboard of the user in the game
        void handleKeys_fct();

        // modify the location of the SDL_texture in function of the classes
        void render();

        // for a specific keyboard event, modify the object Player
        void handleEvent( SDL_Event& e );



    private:
        // ATTRIBUTES
        // size of the window, 
        // https://docs.microsoft.com/en-us/windows/uwp/design/layout/screen-sizes-and-breakpoints-for-responsive-design
        //1024x640, 1366x768, 1920x1080
        int SCREEN_WIDTH = 1366;
        int SCREEN_HEIGHT = 768;

        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;
            

        //The window renderer
        SDL_Renderer* gRenderer = NULL;



        // other present objects

        // its graphical representation:
        SDL_Texture* gUser = NULL;

        // The level, with the terrain and the monsters etc...
        Level level;
        // The graphical representation of the Terrain
        vector<SDL_Texture*> gGrounds; // TODO see if needed
        SDL_Texture* gBackground = NULL;


        // METHODES
        //Loads individual image as SDL_Surface. Not used anymore.
        SDL_Surface* loadSurface(string path);

        //change with the class LTexture to have some animations
        SDL_Texture* loadTexture(std::string path);


};



