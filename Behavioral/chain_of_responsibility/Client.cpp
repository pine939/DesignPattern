//
// Created by kangdasol on 22. 10. 3.
//

#include "RequestHandler.h"
#include "DishWashRequestHandler.h"
#include "LaundryRequestHandler.h"
#include "VacuumRequestHandler.h"

class Client {
public:
    explicit Client(RequestHandler *requestHandler);
    virtual ~Client();
    void Work();
private:
    RequestHandler *requestHandler;
};

Client::Client(RequestHandler *requestHandler) : requestHandler(requestHandler) {}

Client::~Client() {}

void Client::Work() {
    requestHandler->handler(new Request("Work Start!"));
}

int main() {
    RequestHandler *chain = new RequestHandler(new DishWashRequestHandler(new LaundryRequestHandler(new VacuumRequestHandler(
            nullptr))));
    Client *client = new Client(chain);
    client->Work();
    return 0;
}