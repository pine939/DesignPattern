
#include "Shape.h"
#include "Circle.h"
#include "Pen.h"

int main() {
    Shape *shape = new Circle(*new Pen());
    shape->Draw();
    shape->Resize();
    return 0;
}