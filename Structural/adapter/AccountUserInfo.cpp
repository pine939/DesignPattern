//
// Created by kangdasol on 22. 10. 1.
//

#include "AccountUserInfo.h"


AccountUserInfo::AccountUserInfo(Account* account)
{
    this->account = account;
}

AccountUserInfo::~AccountUserInfo() {}

std::string AccountUserInfo::GetUserName()
{
    return this->account->GetAccountName();
}

std::string AccountUserInfo::GetPassword()
{
    return this->account->GetAccountPassword();
}




