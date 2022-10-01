//
// Created by kangdasol on 22. 10. 1.
//

#ifndef ADAPTER_ACCOUNTUSERINFOSERVICE_H
#define ADAPTER_ACCOUNTUSERINFOSERVICE_H


#include "UserInfoService.h"
#include "AccountService.h"

class AccountUserInfoService : public UserInfoService
{
public:
    explicit AccountUserInfoService(AccountService accountService);
    UserInfo* LoadUser(const std::string& username) override;
private:
    AccountService accountService;
};

#endif //ADAPTER_ACCOUNTUSERINFOSERVICE_H
