//
// Created by Danil on 23.03.2020.
//

#ifndef LAB_5_TASK1_POINT_H
#define LAB_5_TASK1_POINT_H


#include <iosfwd>


class Point {
public:
    Point();
    Point(const Point& point);
    Point(float x, float y);
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(float num) const;
    Point operator/(float num) const;
    [[nodiscard]] float get_x() const;
    [[nodiscard]] float get_y() const;
    void set_x(float value);
    void set_y(float value);
    friend std::ostream& operator<<(std::ostream& stream,const Point& point);


private:
    float y;
    float x;
};

#endif //LAB_5_TASK1_POINT_H
