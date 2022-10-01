//
// Created by kangdasol on 22. 10. 1.
//

#ifndef ADAPTER_ACCOUNTSERVICE_H
#define ADAPTER_ACCOUNTSERVICE_H


#include "Account.h"

class AccountService {
public:
    AccountService();
    virtual ~AccountService();
    Account* FindAccountByUserName(const std::string& username);
private:
    Account* account;
};


#endif //ADAPTER_ACCOUNTSERVICE_H
