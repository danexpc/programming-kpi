#include <iostream>
#include "Point.h"
#include "Rectangle.h"

int main() {
    Point point(0, 0);
    Point point1(0, 4);
    Point point2(4, 4);
    Point point3(4, 0);
    Rectangle rectangle(point, point1, point2, point3);
    Rectangle rectangle2(rectangle * 2);
    Rectangle rectangle3(rectangle + rectangle2);
    std::cout << rectangle;
    std::cout << rectangle2;
    std::cout << rectangle3;
    return 0;
}
