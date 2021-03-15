cmake_minimum_required(VERSION 3.7)

project(Game)

set(SRCS
	SDL_game.cpp
  )
    
set(HEADERS
    SDL_game.h
    KeyPressSurface.h
  )
    

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(Game main_test_sdl.cpp ${SRCS} ${HEADERS})
target_link_libraries(Game ${SDL2_LIBRARIES})

