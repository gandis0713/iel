cmake_minimum_required(VERSION 3.12)

SET (SRC_FILES
    main.cpp
    io/File.cpp 
    inc/io/File.h
    inc/std/Vector.h
    )

ADD_LIBRARY(${CMAKE_PROJECT_NAME} STATIC ${SRC_FILES})
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME})