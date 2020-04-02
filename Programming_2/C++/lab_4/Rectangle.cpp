//
// Created by Danil on 17.03.2020.
//

#include "Rectangle.h"
#include "Point.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle(){
    A = Point(0, 0);
    B = Point(0, 0);
    C = Point(0, 0);
    D = Point(0, 0);
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d){
    A = a;
    B = b;
    C = c;
    D = d;
}
Rectangle::Rectangle(Rectangle const &rectangle): Rectangle(rectangle.A, rectangle.B, rectangle.B, rectangle.C){
}

double Rectangle::area() const {
    return sqrt(pow(A.get_X() - B.get_X(), 2) + pow(A.get_Y() - B.get_Y(), 2))
           * sqrt(pow(B.get_X() - C.get_X(), 2) + pow(B.get_Y() - C.get_Y(), 2));
}

double Rectangle::perimeter() const {
    return (sqrt(pow(A.get_X() - B.get_X(), 2) + pow(A.get_Y() - B.get_Y(), 2))
           + sqrt(pow(B.get_X() - C.get_X(), 2) + pow(B.get_Y() - C.get_Y(), 2))) * 2;
}


std::ostream& operator<<(std::ostream&os, const Rectangle& rectangle) {
    return os  << "Points: \n A" << rectangle.A << " B" <<
                                    rectangle.B << " C" <<
                                    rectangle.C << " D" <<
                                    rectangle.D << "\nArea: " <<
                                    rectangle.area() <<"   Perimeter: " <<
                                    rectangle.perimeter() << std::endl;
}

Rectangle operator+(const Rectangle& left, const Rectangle& right) {
    return Rectangle(left.A + right.A, left.B + right.B, left.C + right.C, left.D + right.D);
}

Rectangle operator-(const Rectangle& left, const Rectangle& right) {
    return Rectangle(left.A - right.A, left.B - right.B, left.C - right.C, left.D - right.D);
}

Rectangle operator*(const Rectangle& left, const float & right) {
    return Rectangle(left.A * right, left.B * right, left.C * right, left.D * right);
}

Rectangle operator/(const Rectangle& left, const float & right) {
    return Rectangle(left.A / right, left.B / right, left.C / right, left.D / right);
}
