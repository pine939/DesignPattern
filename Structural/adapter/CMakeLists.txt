CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("adapter")

SET(OUTPUT_FILE adapter)
SET(SRC_FILE
        main.cpp
        UserInfoService.h Account.cpp Account.h AccountService.cpp AccountService.h AccountUserInfo.cpp AccountUserInfo.h AccountUserInfoService.cpp AccountUserInfoService.h LoginHandler.cpp LoginHandler.h)
ADD_EXECUTABLE(${OUTPUT_FILE} ${SRC_FILE})