cmake_minimum_required(VERSION 3.6)

project(resource)

set(CMAKE_CXX_STANDARD 17)


find_package(Boost REQUIRED COMPONENTS system)

include_directories(${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
link_libraries(service_library
               resource_print_library
               resource_library 
               util)
add_compile_options(${DEBUG_COMPILE_OPTIONS})

add_executable(${PROJECT_NAME} main.cpp
                               Resource.cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}
    COMMENT "resource Copy"
)
