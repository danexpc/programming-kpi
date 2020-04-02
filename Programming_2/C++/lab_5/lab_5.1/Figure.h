//
// Created by Danil on 23.03.2020.
//

#ifndef LAB_5_TASK1_FIGURE_H
#define LAB_5_TASK1_FIGURE_H


#include "Point.h"

class Figure {
public:
    Figure(int n, const Point *argv);
    Figure(const Figure &figure);
    ~Figure();
    static double lenSide(Point& point1, Point& point2);
    friend std::ostream& operator<<(std::ostream& stream,const Figure& figure);

private:
    int size;
protected:
    Point *points{};
};


#endif //LAB_5_TASK1_FIGURE_H
