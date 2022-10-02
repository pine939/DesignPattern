//
// Created by kangdasol on 22. 10. 2.
//

#include "CountAction.h"
#include "BookActionImpl.h"

int main()
{
    Action *action = new Action(new BookActionImpl("bible"));
    action->Play();
    return 0;
}