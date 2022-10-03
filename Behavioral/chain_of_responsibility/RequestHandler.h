//
// Created by kangdasol on 22. 10. 3.
//

#ifndef CHAIN_OF_RESPONSIBILITY_REQUESTHANDLER_H
#define CHAIN_OF_RESPONSIBILITY_REQUESTHANDLER_H


#include "Request.h"

class RequestHandler {
public:
    explicit RequestHandler(RequestHandler *requestHandler);
    virtual ~RequestHandler();
    virtual void handler(Request *requset);  // handle the request!
protected:
    RequestHandler *nextHandler;
};


#endif //CHAIN_OF_RESPONSIBILITY_REQUESTHANDLER_H
