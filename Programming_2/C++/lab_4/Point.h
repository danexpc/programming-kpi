//
// Created by Danil on 17.03.2020.
//

#ifndef LAB_4_OP_POINT_H
#define LAB_4_OP_POINT_H


#include <iosfwd>

class Point{
public:
    Point();
    Point(float x, float y);
    [[nodiscard]] float get_X() const;
    void set_X(float value);
    [[nodiscard]] float get_Y() const;
    void set_Y(float value);
    friend Point operator+(const Point& left, const Point& right);
    friend Point operator-(const Point& left, const Point& right);
    friend Point operator/(const Point& left, const float& right);
    friend Point operator*(const Point& left, const float& right);
    friend std::ostream& operator<<(std::ostream& os, Point obj);

private:
    float Y;
    float X;
};


#endif //LAB_4_OP_POINT_H
