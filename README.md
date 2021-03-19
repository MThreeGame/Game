# Authors

Claire Mevolhon
Sameneh Shirdel
Hugo Claing

# Game

Game designed with SDL2.  
<img src="https://github.com/MThreeGame/Game/blob/main/Sample/window.png" width="800">

Use the arrows from your keyboard <img src="https://github.com/MThreeGame/Game/blob/main/Sample/keyarrows.png" width="50"> to move your character.
  
Avoid the trap and monsters and catch all the stars to win! The player has four lives that
are reprensented with four heart images in the top right corner of the window. If the
player encounters a trap or a monster he returns to his starting position and he loses a life.

Good luck!  



## how to build

You must have install the SDL2 library first.

You can have to change the CMakeLists.txt a little depending if you are in linux or Windows.  

In your cloned repository there is already a CMakeLists.  
From your console you can directly:  
```
mkdir build   # will create a new directory
cd build
cmake ..   # will build the makefile and all the dependances on your build directory.
make      # will build your executable
./Game      # to run the program

```
Then we delete the build folder before we push.

## Improvement in the future

We have a class called `LTexture` that would render images instead of doing it in the class
SDL_Game which would make the rendering of image in each window/class easier to process.
It would make the code less redundante and it could permit de rendering of animation such
as spritesheet images.

Our game also has incomplete functionality in the class `Terrain`. Our initial goal was to
read an image encoded in `bmp` format file and return a matrix of integer that would 
represent different kinds grounds of an enum such as `GROUND`, `BACK_GROUND`, `DANGER`,
and so on depending on the color of the image passed. We have already implemented a
function that would check for collision of our character inside the matrix created.

## Choice of design

The design was hard since we had little understand of SDL2 and so it was difficult to
envision what the structure would look like depending on SDL2 technical constraint.

We use the first stategie for designing usable interface which is to make the application
familiar to the user. This is apparent in the goal of the game (catching all the star and
evading the monster or other traps).




