//
// Created by Danil on 23.03.2020.
//

#include "Point.h"
#include <iostream>


Point::Point(): x(0), y(0){}

Point::Point(const Point &point): x(point.x), y(point.y) {}

Point::Point(float x, float y): x(x), y(y) {}

Point Point::operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point &other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator*(float num) const {
    return Point(x * num, y * num);
}

Point Point::operator/(float num) const {
    return Point(x / num, y / num);
}


std::ostream& operator<<(std::ostream& stream,const Point& point) {
    stream << "(" << point.x << ", " << point.y << ")" << std::endl;
    return stream;
}

float Point::get_x() const {
    return x;
}

float Point::get_y() const {
    return y;
}

void Point::set_x(float value){
    x = value;
}

void Point::set_y(float value) {
    y = value;
}
