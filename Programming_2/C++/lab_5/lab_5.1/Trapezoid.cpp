//
// Created by Danil on 23.03.2020.
//
#include <cmath>
#include <ostream>
#include "Trapezoid.h"

Trapezoid::Trapezoid(const Point *argv): Figure(size, argv) {}

double Trapezoid::Area() const {
    return  (lenSide(points[0], points[3]) + lenSide(points[1], points[2])) *
    std::fabs(points[1].get_y() - points[0].get_y()) / 2;
}

double Trapezoid::Perimeter() const {
    return round(lenSide(points[0], points[1])
                      + lenSide(points[1], points[2])
                      + lenSide(points[2], points[3])
                      + lenSide(points[0], points[3]));
}

std::ostream &operator<<(std::ostream &stream, const Trapezoid &trapezoid) {
    for (int i = 0; i < Trapezoid::size; i++)
    {
        stream << "Point" << i+1 << ": " << trapezoid.points[i] << std::endl;
    }
    stream << "\nArea: " << trapezoid.Area() << "\nPerimeter: " << trapezoid.Perimeter() << std::endl;
    return stream;
}



