CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("observer")

SET(OUTPUT_FILE observer)
SET(SRC_FILE
        Observer.cpp ../stragety/Strategy.cpp)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})