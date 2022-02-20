cmake_minimum_required(VERSION 3.21)
project(CS2303FinalHomework)
include_directories(Fleets)
include_directories(ships)
include_directories(tests)
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE allFile *.c *.cpp)
add_executable(CS2303FinalHomework ${allFile})


