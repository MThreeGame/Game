cmake_minimum_required(VERSION 3.17)
project(Game)
add_executable(Game main.cpp SDL_game.cpp LTexture.cpp Character.cpp Player.cpp Level.cpp
        Terrain.cpp SDL_game.h KeyPressSurface.h LTexture.h Character.h Player.h Level.h Terrain.h Star.cpp Star.h winWindow.h winWindow.cpp Monster.h Monster.cpp)

set(SDL2_LIB_DIR SDL2/lib)
set(SDL2_INCLUDE_DIR SDL2/include/SDL2)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
target_link_libraries(Game -lmingw32 -lSDL2main -lSDL2 -mwindows)


