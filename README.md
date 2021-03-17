# Game
Game designed with SDL2.  
  
Use the arrows from your keyboard to move your character. Avoid the trap and catch all the stars!  



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
