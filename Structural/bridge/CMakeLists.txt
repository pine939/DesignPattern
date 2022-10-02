CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("bridge")

SET(OUTPUT_FILE bridge)
SET(SRC_FILE
        main.cpp
        Action.h
        ActionImpl.h
        CountAction.h
        BookActionImpl.cpp
        BookActionImpl.h
        )
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})