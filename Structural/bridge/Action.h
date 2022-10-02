//
// Created by kangdasol on 22. 10. 2.
//

#ifndef DESIGNPATTERN_ACTION_H
#define DESIGNPATTERN_ACTION_H

#include "ActionImpl.h"

class Action
{
public:
    Action(ActionImpl *action)
    {
        actionImpl = action;
    }
    virtual void Start()
    {
        actionImpl->RawStart();
    }
    virtual void Act()
    {
        actionImpl->RawAct();
    }
    virtual void End()
    {
        actionImpl->RawEnd();
    }

    virtual void Play()
    {
        Start();
        Act();
        End();
    }
private:
    ActionImpl *actionImpl;  // Interface(Bridge)
};
#endif //DESIGNPATTERN_ACTION_H
