cmake_minimum_required(VERSION 3.6)

project(test_project)

set(CMAKE_CXX_STANDARD 17)

set(RESOURCE_TEST resource_test)
set(PRINT_TEST print_test)


message(hello ----  ${DEBUG_COMPILE_OPTIONS})
add_executable(${RESOURCE_TEST} resource_test.cpp)
target_compile_options(${RESOURCE_TEST} PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_include_directories(${RESOURCE_TEST} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${RESOURCE_TEST} resource_library util)
add_custom_command(TARGET ${RESOURCE_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${RESOURCE_TEST}> ${CMAKE_SOURCE_DIR}/${RESOURCE_TEST}
    COMMENT "resource_test Copy"
)

add_executable(${PRINT_TEST} print_test.cpp)
target_compile_options(${PRINT_TEST} PRIVATE ${DEBUG_COMPILE_OPTIONS})
target_include_directories(${PRINT_TEST} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PRINT_TEST} resource_library util resource_print_library)
add_custom_command(TARGET ${PRINT_TEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PRINT_TEST}> ${CMAKE_SOURCE_DIR}/${PRINT_TEST}
    COMMENT "print_test Copy"
)

