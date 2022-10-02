//
// Created by kangdasol on 22. 10. 2.
//

#ifndef BRIDGE_BOOKACTIONIMPL_H
#define BRIDGE_BOOKACTIONIMPL_H


#include "ActionImpl.h"

class BookActionImpl : public ActionImpl {
public:
    explicit BookActionImpl(const char* title);

    void RawStart() override;
    void RawAct() override;
    void RawEnd() override;
private:
    std::string booktitle;
};


#endif //BRIDGE_BOOKACTIONIMPL_H
