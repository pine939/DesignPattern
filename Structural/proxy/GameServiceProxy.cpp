//
// Created by kangdasol on 22. 10. 3.
//

#include <iostream>
#include <chrono>
#include "GameServiceProxy.h"
#include "ConcreteGameService.h"

void GameServiceProxy::GameStart() {
    auto start = std::chrono::system_clock::now();
    GameService *gameService1 = new ConcreteGameService();
    gameService1->GameStart();
    for (int i = 0; i < 10000000; i++) {}
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "loading time : " << elapsed_seconds.count() << std::endl;
}