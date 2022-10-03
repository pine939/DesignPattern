//
// Created by kangdasol on 22. 10. 3.
//

#include "Request.h"
#include <utility>

Request::Request(std::string body) : body(std::move(body)){}
Request::~Request() {}
std::string Request::GetBody() {
    return this->body;
}

void Request::SetBody(std::string body) {
    this->body = body;
}