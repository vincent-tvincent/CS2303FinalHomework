cmake_minimum_required(VERSION 3.21)
project(CS2303FinalHomework)
include_directories(battleship)
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE allFile battleship/*.c battleship/*.cpp)
add_executable(CS2303FinalHomework ${allFile})




