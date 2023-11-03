cmake_minimum_required(VERSION 3.6)

project(service_library)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES ServiceInterface.cpp
            PrintService.cpp
            ServerService.cpp
            ServiceFactory.cpp
            SystemResourceService.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)
