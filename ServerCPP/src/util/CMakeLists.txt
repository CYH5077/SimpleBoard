cmake_minimum_required(VERSION 3.6)

project(util)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES Result.cpp
            StringUtil.cpp
)
add_library(${PROJECT_NAME} ${SOURCES})