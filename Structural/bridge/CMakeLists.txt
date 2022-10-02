CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("bridge")

SET(OUTPUT_FILE bridge)
SET(SRC_FILE
        main.cpp
        Shape.h
        Tool.h Circle.cpp Circle.h Pen.cpp Pen.h)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})