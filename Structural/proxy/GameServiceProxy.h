//
// Created by kangdasol on 22. 10. 3.
//

#ifndef PROXY_GAMESERVICEPROXY_H
#define PROXY_GAMESERVICEPROXY_H


#include "GameService.h"

class GameServiceProxy : public GameService {
public:
    void GameStart() override;
};


#endif //PROXY_GAMESERVICEPROXY_H
