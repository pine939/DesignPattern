//
// Created by kangdasol on 22. 10. 1.
//

#ifndef ADAPTER_ACCOUNT_H
#define ADAPTER_ACCOUNT_H


#include <string>

class Account
{
public:
    std::string GetAccountName();
    std::string GetAccountPassword();
    std::string GetAccountEmail();
    void SetAccountName(const std::string& name);
    void SetAccountPassword(const std::string& password);
    void SetAccountEmail(const std::string& email);
private:
    std::string email;
    std::string name;
    std::string password;
};


#endif //ADAPTER_ACCOUNT_H
