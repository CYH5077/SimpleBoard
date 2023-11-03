cmake_minimum_required(VERSION 3.6)

project(simple_board) 

set(CMAKE_CXX_STANDARD 17)

#set(COMPILE_OPTIONS -g -ggdb)
set(COMPILE_OPTIONS -O3)

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(${COMPILE_OPTIONS})

add_subdirectory(src)
