cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME iel)
set(NAME_SPACE ${PROJECT_NAME})
set(SRC_DIR src)

project(
  ${PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "Inefficient Library for c++"
  LANGUAGES CXX)


add_compile_definitions(_IEL_NAME_SPACE_=${NAME_SPACE})

add_executable (${PROJECT_NAME} ${SRC_DIR}/main.cpp)