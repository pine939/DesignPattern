//
// Created by kangdasol on 22. 10. 3.
//

#include "GameServiceProxy.h"

int main() {
    GameService *service = new GameServiceProxy();
    service->GameStart();
    return 0;
}