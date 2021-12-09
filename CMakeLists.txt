cmake_minimum_required(VERSION 3.12)

# initilize project.
set(IEL_PROJECT_NAME iel)
project(
  ${IEL_PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "Inefficient Library for c++"
  LANGUAGES CXX)

# set options.
option(TEST_SPEC "Test spec" OFF)

# set compile options.
set(CMAKE_CXX_STANDARD 17)

# set variables.
set(SRC_DIR src)
set(EXTERNAL_DIR externals)
if(TEST_SPEC)
  set(SPEC_DIR spec)
  set(GTEST_DIR ${EXTERNAL_DIR}/googletest)
endif()

# set compile definitions.
add_compile_definitions(CPP_VERSION=${CMAKE_CXX_STANDARD})

# set build project list
add_subdirectory(${SRC_DIR})
if(TEST_SPEC)
  add_subdirectory(${SPEC_DIR})
  add_subdirectory(${GTEST_DIR})
endif()







