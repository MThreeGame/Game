cmake_minimum_required(VERSION 3.7)

project(Game)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Game HelloWordSDL.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})

