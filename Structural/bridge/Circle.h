//
// Created by kangdasol on 22. 10. 2.
//

#ifndef BRIDGE_CIRCLE_H
#define BRIDGE_CIRCLE_H


#include "Shape.h"
#include "Tool.h"

class Circle : public Shape {
public:
    explicit Circle(Tool &tool1) : tool(tool1) {}
    void Draw() override;
    void Resize() override;
private:
    Tool &tool;
};


#endif //BRIDGE_CIRCLE_H
