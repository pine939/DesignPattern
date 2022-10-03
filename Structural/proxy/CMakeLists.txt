CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("proxy")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(OUTPUT_FILE proxy)
SET(SRC_FILE
        main.cpp
        GameService.h ConcreteGameService.cpp ConcreteGameService.h GameServiceProxy.cpp GameServiceProxy.h)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})