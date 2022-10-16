CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("factory")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(OUTPUT_FILE factory)
SET(SRC_FILE
        #SimpleFactory.cpp)
        MethodFactory.cpp)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})