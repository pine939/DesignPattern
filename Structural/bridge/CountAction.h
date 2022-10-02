//
// Created by kangdasol on 22. 10. 2.
//

#ifndef BRIDGE_COUNTACTION_H
#define BRIDGE_COUNTACTION_H


#include "Action.h"

class CountAction : public Action {
public:
    void MultipleAction()
    {
        Start();
        for (int i = 0; i < 5; i++)
        {
            Act();
        }
        End();
    }
};


#endif //BRIDGE_COUNTACTION_H
