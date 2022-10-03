//
// Created by kangdasol on 22. 10. 3.
//

#include <iostream>
#include "LaundryRequestHandler.h"

LaundryRequestHandler::LaundryRequestHandler(RequestHandler *requestHandler) : RequestHandler(requestHandler) {}

void LaundryRequestHandler::handler(Request *request) {
    request->SetBody("Handle Laundry");
    //nextHandler->handler(request);
    RequestHandler::handler(request);
}