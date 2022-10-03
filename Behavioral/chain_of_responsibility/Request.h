//
// Created by kangdasol on 22. 10. 3.
//

#ifndef CHAIN_OF_RESPONSIBILITY_REQUEST_H
#define CHAIN_OF_RESPONSIBILITY_REQUEST_H


#include <string>

class Request {
public:
    explicit Request(std::string body);
    virtual ~Request();
    std::string GetBody();
    void SetBody(std::string body);
private:
    std::string body;
};


#endif //CHAIN_OF_RESPONSIBILITY_REQUEST_H
