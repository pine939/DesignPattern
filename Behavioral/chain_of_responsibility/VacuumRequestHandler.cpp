//
// Created by kangdasol on 22. 10. 3.
//

#include <iostream>
#include "VacuumRequestHandler.h"

VacuumRequestHandler::VacuumRequestHandler(RequestHandler *requestHandler) : RequestHandler(requestHandler) {}

void VacuumRequestHandler::handler(Request *request) {
    request->SetBody("Handle Vacuum");
    //nextHandler->handler(request);
    RequestHandler::handler(request);
}