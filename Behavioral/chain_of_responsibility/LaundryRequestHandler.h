//
// Created by kangdasol on 22. 10. 3.
//

#ifndef CHAIN_OF_RESPONSIBILITY_LAUNDRYREQUESTHANDLER_H
#define CHAIN_OF_RESPONSIBILITY_LAUNDRYREQUESTHANDLER_H


#include "RequestHandler.h"

class LaundryRequestHandler : public RequestHandler {
public:
    explicit LaundryRequestHandler(RequestHandler *requestHandler);
    void handler(Request *request) override;
};


#endif //CHAIN_OF_RESPONSIBILITY_LAUNDRYREQUESTHANDLER_H
