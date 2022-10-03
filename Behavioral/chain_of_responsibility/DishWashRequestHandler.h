//
// Created by kangdasol on 22. 10. 3.
//

#ifndef CHAIN_OF_RESPONSIBILITY_DISHWASHREQUESTHANDLER_H
#define CHAIN_OF_RESPONSIBILITY_DISHWASHREQUESTHANDLER_H


#include "RequestHandler.h"

class DishWashRequestHandler : public RequestHandler {
public:
    explicit DishWashRequestHandler(RequestHandler *requestHandler);

    void handler(Request *request) override;
};


#endif //CHAIN_OF_RESPONSIBILITY_DISHWASHREQUESTHANDLER_H
