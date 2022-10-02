//
// Created by kangdasol on 22. 10. 2.
//

#include <iostream>
#include "Circle.h"

void Circle::Draw() {
    std::cout << "draw circle by " << tool.GetToolName() << std::endl;
}

void Circle::Resize() {
    std::cout << "resize circle by " << tool.GetToolName() << std::endl;
}
