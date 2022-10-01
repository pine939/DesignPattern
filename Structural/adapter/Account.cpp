//
// Created by kangdasol on 22. 10. 1.
//

#include "Account.h"

std::string Account::GetAccountName()
{
    return this->name;
}

std::string Account::GetAccountPassword()
{
    return this->password;
}

std::string Account::GetAccountEmail()
{
    return this->email;
}

void Account::SetAccountEmail(const std::string& email)
{
    this->email = email;
}

void Account::SetAccountPassword(const std::string& password)
{
    this->password = password;
}

void Account::SetAccountName(const std::string& name)
{
    this->name = name;
}
