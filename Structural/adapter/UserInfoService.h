//
// Created by kangdasol on 22. 10. 1.
//


#ifndef DESIGNPATTERN_USERINFOSERVICE_H
#define DESIGNPATTERN_USERINFOSERVICE_H

#include "UserInfo.h"
class UserInfoService
{
public:
    virtual UserInfo* LoadUser(const std::string& username) = 0;
};
#endif //DESIGNPATTERN_USERINFOSERVICE_H
