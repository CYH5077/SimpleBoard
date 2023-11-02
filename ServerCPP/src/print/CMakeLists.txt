cmake_minimum_required(VERSION 3.6)

project(resource_print_library)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES ProgressBar.cpp
            FontColor.cpp
            TitleBar.cpp
            PrintInterface.cpp
            PrintCPUInterfaceInfo.cpp
            PrintMemoryUsageInfo.cpp
            PrintNetworkUsageInfo.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)
