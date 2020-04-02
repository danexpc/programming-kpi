//
// Created by Danil on 17.03.2020.
//


#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(){
    X = 0;
    Y = 0;
}

Point::Point(float x, float y) {
    X = x;
    Y = y;
}

float Point::get_X() const {
    return X;
}
void Point::set_X(float value)
{
    X = value;
}
float Point::get_Y() const {
    return Y;
}
void Point::set_Y(float value)
{
    Y = value;
}
std::ostream& operator<<(std::ostream&os, Point point) {
    return os  << '(' << point.get_X() << ", " << point.get_Y() << ')' << endl;
}

Point operator+(const Point& left, const Point& right) {
    return Point(left.X + right.X, left.Y + right.Y);
}

Point operator-(const Point& left, const Point& right) {
    return Point(left.X - right.X, left.Y - right.Y);
}

Point operator*(const Point& left, const float& right) {
    return Point(left.X * right, left.Y * right);
}

Point operator/(const Point& left, const float& right) {
    return Point(left.X / right, left.Y / right);
}



