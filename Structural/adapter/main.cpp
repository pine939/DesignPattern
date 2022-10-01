//
// Created by kangdasol on 22. 10. 1.
//

#include <iostream>
#include "AccountService.h"
#include "UserInfoService.h"
#include "AccountUserInfoService.h"
#include "LoginHandler.h"

int main()
{
    AccountService accountService;
    UserInfoService *userInfoService = new AccountUserInfoService(accountService);

    LoginHandler *loginHandler = new LoginHandler(userInfoService);
    std::string loginStr = loginHandler->Login("pine939", "pine939");

    std::cout << loginStr << std::endl;
    return 0;
}