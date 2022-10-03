//
// Created by kangdasol on 22. 10. 3.
//

#include <iostream>
#include "DishWashRequestHandler.h"

DishWashRequestHandler::DishWashRequestHandler(RequestHandler *requestHandler) : RequestHandler(requestHandler) {}

void DishWashRequestHandler::handler(Request *request) {
    request->SetBody("Handle Dish Wash");
    //nextHandler->handler(request);
    RequestHandler::handler(request);
}