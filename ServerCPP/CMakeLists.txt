cmake_minimum_required(VERSION 3.6)

project(simple_board) 

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
set(DEBUG_COMPILE_OPTIONS -g -ggdb)

add_subdirectory(src)

target_compile_options(util PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_compile_options(resource_library PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_compile_options(resource_server PRIVATE ${DEBUG_COMPILE_OPTIONS})

