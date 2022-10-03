//
// Created by kangdasol on 22. 10. 3.
//

#include <iostream>
#include "RequestHandler.h"

RequestHandler::RequestHandler(RequestHandler *requestHandler) : nextHandler(requestHandler){}

void RequestHandler::handler(Request *request) {
    std::cout << request->GetBody() << std::endl;
    if (!nextHandler) return;
    nextHandler->handler(request);
}

RequestHandler::~RequestHandler() {}
