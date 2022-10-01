//
// Created by kangdasol on 22. 10. 1.
//

#ifndef DESIGNPATTERN_USERINFO_H
#define DESIGNPATTERN_USERINFO_H

#include <string>
class UserInfo
{
public:
    virtual std::string GetUserName() = 0;
    virtual std::string GetPassword() = 0;
};
#endif //DESIGNPATTERN_USERINFO_H
