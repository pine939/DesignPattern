//
// Created by kangdasol on 22. 10. 1.
//

#ifndef ADAPTER_ACCOUNTUSERINFO_H
#define ADAPTER_ACCOUNTUSERINFO_H


#include "UserInfo.h"
#include "Account.h"

class AccountUserInfo : public UserInfo
{
public:
    explicit AccountUserInfo(Account *account);
    virtual ~AccountUserInfo();
    std::string GetUserName() override;
    std::string GetPassword() override;
private:
    Account *account;
};


#endif //ADAPTER_ACCOUNTUSERINFO_H
