cmake_minimum_required(VERSION 3.21)
project(CS2303FinalHomework)
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE allFile final/*.h final/*.cpp )
add_executable(CS2303FinalHomework ${allFile})




