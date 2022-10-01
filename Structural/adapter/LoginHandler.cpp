//
// Created by kangdasol on 22. 10. 1.
//

#include <iostream>
#include "LoginHandler.h"

LoginHandler::LoginHandler(UserInfoService *userInfoService)
                : userInfoService1(userInfoService) {}

LoginHandler::~LoginHandler() {}

std::string LoginHandler::Login(const std::string& username, const std::string& password)
{
    UserInfo *userInfo = userInfoService1->LoadUser(username);
    if (userInfo->GetPassword() == password)
    {
        std::cout << "login success!" << std::endl;
        return userInfo->GetPassword();
    }
    else
    {
        std::cout << "login fail!" << std::endl;
    }
    return std::string();
}
