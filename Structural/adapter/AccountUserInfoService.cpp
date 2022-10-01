//
// Created by kangdasol on 22. 10. 1.
//

#include "AccountUserInfoService.h"
#include "AccountUserInfo.h"

AccountUserInfoService::AccountUserInfoService(AccountService accountService)
{
    this->accountService = accountService;
}

UserInfo* AccountUserInfoService::LoadUser(const std::string& username)
{
    return new AccountUserInfo(accountService.FindAccountByUserName(username));
}

