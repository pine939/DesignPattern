//
// Created by kangdasol on 22. 10. 2.
//

#ifndef DESIGNPATTERN_ACTIONIMPL_H
#define DESIGNPATTERN_ACTIONIMPL_H

class ActionImpl
{
public:
    virtual void RawStart() = 0;
    virtual void RawAct() = 0;
    virtual void RawEnd() = 0;
};
#endif //DESIGNPATTERN_ACTIONIMPL_H
