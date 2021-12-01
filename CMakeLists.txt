cmake_minimum_required(VERSION 3.12)

# initilize project.
set(PROJECT_NAME iel)
project(
  ${PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "Inefficient Library for c++"
  LANGUAGES CXX)

# set options.
option(TEST_SPEC "Test spec or not" OFF)

# set compile options.
set(CMAKE_CXX_STANDARD 17)

# set variables.
set(NAME_SPACE ${PROJECT_NAME})
set(SRC_DIR src)
set(EXTERNAL_DIR externals)
if(TEST_SPEC)
  set(SPEC_DIR spec)
  set(GTEST_DIR ${EXTERNAL_DIR}/googletest)
endif()

# set compile definitions.
add_compile_definitions(_IEL_NAME_SPACE_=${NAME_SPACE})

# set build project list
add_subdirectory(${SRC_DIR})
if(TEST_SPEC)
  add_subdirectory(${SPEC_DIR})
  add_subdirectory(${GTEST_DIR})
endif()







