//
// Created by Danil on 23.03.2020.
//

#ifndef LAB_5_TASK1_TRAPEZOID_H
#define LAB_5_TASK1_TRAPEZOID_H


#include "Figure.h"

class Trapezoid : public Figure{
public:
    explicit Trapezoid(const Point *argv);
    [[nodiscard]] double Area() const;
    [[nodiscard]] double Perimeter() const;
    friend std::ostream& operator<<(std::ostream& stream,const Trapezoid& trapezoid);


private:
    static const int size = 4;
};


#endif //LAB_5_TASK1_TRAPEZOID_H
