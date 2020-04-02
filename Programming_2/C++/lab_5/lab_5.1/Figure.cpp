//
// Created by Danil on 23.03.2020.
//
#include <ostream>
#include "Figure.h"
#include <cmath>


Figure::Figure(int n, const Point *argv) : size(n){
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = argv[i];
    }
}

Figure::Figure(const Figure &figure) : size(figure.size) {
    for (int i = 0; i < size; i++)
    {
        points[i] = figure.points[i];
    }
}

double Figure::lenSide(Point &point1, Point& point2){
    return sqrt(pow(point1.get_x() - point2.get_x(), 2) + pow(point1.get_y() - point2.get_y(), 2));
}

std::ostream &operator<<(std::ostream &stream, const Figure &figure) {
    for (int i = 0; i < figure.size; i++)
    {
        stream << "Point" << i+1 << ": " << figure.points[i] << std::endl;
    }
    return stream;
}

Figure::~Figure() {
    delete points;
}


