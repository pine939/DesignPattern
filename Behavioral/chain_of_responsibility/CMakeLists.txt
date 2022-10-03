CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("chain_of_responsibility")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(OUTPUT_FILE chain_of_responsibility)
SET(SRC_FILE
        Request.cpp Request.h RequestHandler.cpp RequestHandler.h DishWashRequestHandler.cpp DishWashRequestHandler.h LaundryRequestHandler.cpp LaundryRequestHandler.h VacuumRequestHandler.cpp VacuumRequestHandler.h Client.cpp)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})