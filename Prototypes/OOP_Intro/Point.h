#ifndef OOP_INTRO_POINT_H
#define OOP_INTRO_POINT_H

#include <iostream>

class Point
{
public:
    Point(double x, double y);
    double getX();
    double getY();
    ~Point();

private:
    double x;
    double y;
};

#endif //OOP_INTRO_POINT_H
