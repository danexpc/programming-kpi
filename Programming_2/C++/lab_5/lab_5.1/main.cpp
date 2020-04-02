#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Trapezoid.h"

int main() {
    Point point(0, 0);
    Point point2(1, 5);
    Point point3(5, 5);
    Point point4(5, 0);
    std::cout << point << std::endl;
    const int n = 2;
    Point points[n]{point, point2};
    Figure figure(n, points);
    std::cout << figure << std::endl;
    Point pointsTr[4]{point, point2, point3, point4};
    Trapezoid trapezoid(pointsTr);
    std::cout << trapezoid << std::endl;
    return 0;
}
