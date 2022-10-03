//
// Created by kangdasol on 22. 10. 3.
//

#ifndef CHAIN_OF_RESPONSIBILITY_VACUUMREQUESTHANDLER_H
#define CHAIN_OF_RESPONSIBILITY_VACUUMREQUESTHANDLER_H


#include "Request.h"
#include "RequestHandler.h"

class VacuumRequestHandler : public RequestHandler{
public:
    explicit VacuumRequestHandler(RequestHandler *requestHandler);
    void handler(Request *request) override;
};


#endif //CHAIN_OF_RESPONSIBILITY_VACUUMREQUESTHANDLER_H
