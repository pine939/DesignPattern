//
// Created by kangdasol on 22. 10. 2.
//

#include <iostream>
#include "BookActionImpl.h"

BookActionImpl::BookActionImpl(const char *title)
{
    booktitle = title;
}

void BookActionImpl::RawStart()
{
    std::cout << "open " << booktitle << std::endl;
}

void BookActionImpl::RawAct()
{
    std::cout << "read " << booktitle << std::endl;
}

void BookActionImpl::RawEnd()
{
    std::cout << "close " << booktitle << std::endl;
}





