cmake_minimum_required(VERSION 3.6)

project(resource_library)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES CPUResource.cpp
            CPUUsageInfo.cpp
            CPUInterfaceInfo.cpp
            MemoryResource.cpp
            MemoryUsageInfo.cpp
            NetworkUsageInfo.cpp
            NetworkResource.cpp
            NetworkInterfaceList.cpp
            SystemInterfaceInfo.cpp
            SystemResource.cpp
            SystemUsageInfo.cpp
            ThreadCPUUsage.cpp
            ThreadMemoryUsage.cpp
            ThreadNetworkUsage.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)
