##
## mSFML
##

cmake_minimum_required(VERSION 3.5)
project(msfml)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/srcs)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g3")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(msfml main.cpp srcs/Audio.cpp srcs/Window.cpp srcs/TextureManager.cpp srcs/Timer.cpp srcs/AnimatedSprite.cpp srcs/Animation.cpp)
target_link_libraries(msfml sfml-window sfml-system sfml-audio sfml-graphics)
