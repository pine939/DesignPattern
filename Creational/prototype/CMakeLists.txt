CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("prototype")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(OUTPUT_FILE prototype)
SET(SRC_FILE
        ProtoType.cpp)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})