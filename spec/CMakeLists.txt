cmake_minimum_required(VERSION 3.12)

SET(BINARY test_spec)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(${BINARY} ${TEST_SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME} gtest)