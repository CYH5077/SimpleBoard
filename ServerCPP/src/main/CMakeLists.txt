cmake_minimum_required(VERSION 3.6)

project(resource_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} resource_library util)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}
    COMMENT "CMake Build, Copy Success"
)

