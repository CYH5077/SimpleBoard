cmake_minimum_required(VERSION 3.6)

project(test_project)

set(CMAKE_CXX_STANDARD 17)

set(RESOURCE_TEST resource_test)
set(PRINT_TEST print_test)
set(UTIL_TEST util_test)
set(SERVICE_TEST service_test)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_libraries(service_library
               resource_print_library
               resource_library 
               util)
add_compile_options(${DEBUG_COMPILE_OPTIONS})


add_executable(${RESOURCE_TEST} resource_test.cpp)
add_custom_command(TARGET ${RESOURCE_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${RESOURCE_TEST}> ${CMAKE_SOURCE_DIR}/${RESOURCE_TEST}
    COMMENT "resource_test Copy"
)

add_executable(${PRINT_TEST} print_test.cpp)
add_custom_command(TARGET ${PRINT_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PRINT_TEST}> ${CMAKE_SOURCE_DIR}/${PRINT_TEST}
    COMMENT "print_test Copy"
)


add_executable(${UTIL_TEST} util_test.cpp)
add_custom_command(TARGET ${UTIL_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${UTIL_TEST}> ${CMAKE_SOURCE_DIR}/${UTIL_TEST}
    COMMENT "util_test Copy"
)

add_executable(${SERVICE_TEST} service_test.cpp)
add_custom_command(TARGET ${SERVICE_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${SERVICE_TEST}> ${CMAKE_SOURCE_DIR}/${SERVICE_TEST}
    COMMENT "service_test Copy"
)
