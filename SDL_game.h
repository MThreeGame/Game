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

// class SDL_game Starts up SDL and creates window and handle key presses
class SDL_game{
    public:
        SDL_game(){}
        //Starts up SDL and creates window
        bool init();
        //Loads media : load all the images for the different object represenations
        bool loadMedia();
        //Frees media and shuts down SDL
        void close();
        // blit the background
        //void blitSurface();
        //main function, called by main where we handle the keyboard of the user in the game.
        // return -1 if the user closes the Window, 0 if he loses, 1 if he wins.
        int handleKeys_fct();
        // modify the location of the SDL_texture in function of the classes
        // then display again the new renderer to the screen.
        void render();
        // for a specific keyboard event, modify the object Player.velocity.
        // called by handleKeys_fct
        void handleEvent( SDL_Event& e );
        Level getLevel();
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
        // The different Objects and their representations
        // all the objects required (Player, Background, Monsters ...)
        // are all stored into the object level (with their position, pathToImage etc...).
        Level level;
        // The graphical representation of the Terrain
        //vector<SDL_Texture*> gGrounds; // TODO see if needed
        SDL_Texture* gBackground = NULL;
        // graphical representation of the user:
        SDL_Texture* gUser = NULL;
        // graphical representation of the life (hearts)
        SDL_Texture* gLife = NULL; // 1366
        // by default the user has 4 lifes max.
        vector<SDL_Rect> lifePosition = {{1200, 2, 30, 32}, {1235, 2, 30, 32}, {1270, 2, 30, 32}, {1310, 2, 30, 32}};
        // graphical representation of monster
        SDL_Texture* gMonster = NULL;
        // graphical representation of the user:
        SDL_Texture* gStar = NULL;
         //METHODES used for load image for SDL
        //Loads individual image as SDL_Surface. Not used anymore.
        SDL_Surface* loadSurface(string path);
        //change with the class LTexture to have some animations
        SDL_Texture* loadTexture(std::string path);
};



