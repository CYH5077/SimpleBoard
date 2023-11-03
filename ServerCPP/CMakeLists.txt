cmake_minimum_required(VERSION 3.6)

project(simple_board) 

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
set(DEBUG_COMPILE_OPTIONS -g -ggdb)
#set(DEBUG_COMPILE_OPTIONS -O3 -Wall)

add_subdirectory(src)

target_compile_options(util PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_compile_options(resource_library PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_compile_options(resource_print_library PRIVATE ${DEBUG_COMPILE_OPTIONS})