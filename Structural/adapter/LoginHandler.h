//
// Created by kangdasol on 22. 10. 1.
//

#ifndef ADAPTER_LOGINHANDLER_H
#define ADAPTER_LOGINHANDLER_H


#include <string>
#include "UserInfoService.h"

class LoginHandler
{
public:
    explicit LoginHandler(UserInfoService *userInfoService);
    virtual ~LoginHandler();

    std::string Login(const std::string& username, const std::string& password);
private:
    UserInfoService* userInfoService1;
};


#endif //ADAPTER_LOGINHANDLER_H
