//
// Created by kangdasol on 22. 10. 3.
//

#ifndef PROXY_CONCRETEGAMESERVICE_H
#define PROXY_CONCRETEGAMESERVICE_H


#include "GameService.h"

class ConcreteGameService : public GameService {
public:
    void GameStart() override;
};


#endif //PROXY_CONCRETEGAMESERVICE_H
