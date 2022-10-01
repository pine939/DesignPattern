//
// Created by kangdasol on 22. 10. 1.
//

#include "AccountService.h"

AccountService::AccountService()
{
    account = new Account();
}

AccountService::~AccountService()
{
    delete account;
}

Account* AccountService::FindAccountByUserName(const std::string& username)
{
    account->SetAccountName(username);
    account->SetAccountPassword(username);
    account->SetAccountEmail(username);

    return account;
}