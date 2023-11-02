cmake_minimum_required(VERSION 3.6)

project(util)

set(CMAKE_CXX_STANDARD 17)


set(SOURCES Result.cpp
            ResultList.cpp
            StringUtil.cpp
            ThreadManager.cpp
            ArgvUtil.cpp
            ArgvItem.cpp)
add_library(${PROJECT_NAME} ${SOURCES})


include_directories(${CMAKE_SOURCE_DIR}/include)