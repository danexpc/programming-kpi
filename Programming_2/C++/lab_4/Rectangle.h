//
// Created by Danil on 17.03.2020.
//

#ifndef LAB_4_OP_RECTANGLE_H
#define LAB_4_OP_RECTANGLE_H

#include "Point.h"

class Rectangle {
public:
    Rectangle();
    Rectangle(Point a, Point b, Point c, Point d);
    Rectangle(Rectangle const &rectangle);
    std::string get_A();
    void set_A(Point point);
    std::string get_B();
    void set_B(Point point);
    std::string get_C();
    void set_C(Point point);
    std::string get_D();
    void set_D(Point point);
    [[nodiscard]] double area() const;
    [[nodiscard]] double perimeter() const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
    friend Rectangle operator+(const Rectangle& left, const Rectangle& right);
    friend Rectangle operator-(const Rectangle& left, const Rectangle& right);
    friend Rectangle operator/(const Rectangle& left, const float& right);
    friend Rectangle operator*(const Rectangle& left, const float& right);
    Point A, B, C, D;


};


#endif //LAB_4_OP_RECTANGLE_H
