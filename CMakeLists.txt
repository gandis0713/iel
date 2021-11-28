cmake_minimum_required(VERSION 3.12)

project(
  iel
  VERSION 0.1
  DESCRIPTION "Inefficient Library for c++"
  LANGUAGES CXX)

add_compile_definitions(_IEL_NAME_SPACE_=iel)

add_executable (iel src/main.cpp)