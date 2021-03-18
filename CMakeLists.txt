cmake_minimum_required(VERSION 3.7)
project(Game)
set(SRCS
  SDL_game.cpp
  LTexture.cpp
  Character.cpp
  Player.cpp
  Level.cpp
  Terrain.cpp
  Monster.cpp
  Star.cpp
  )
    
set(HEADERS
    SDL_game.h
    KeyPressSurface.h
    LTexture.h
    Character.h
    Player.h
    Level.h
    Terrain.h
    Monster.h
    Star.h
  )
    
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lSDL_Image")
find_package(SDL2 REQUIRED)
#find_package(SDL2IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} )#${SDL2IMAGE_INCLUDE_DIRS})
add_executable(Game main_test_sdl.cpp ${SRCS} ${HEADERS})
target_link_libraries(Game ${SDL2_LIBRARIES}) # ${SDL2IMAGE_INCLUDE_DIRS})
