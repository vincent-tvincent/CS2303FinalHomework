cmake_minimum_required(VERSION 3.21)
project(CS2303FinalHomework)
include_directories(battleship)
include_directories(Tests)
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE allFile battleship/*.h battleship/*.cpp)
add_executable(CS2303FinalHomework ${allFile})




