
#ifndef OOP_INTRO_LINE_H
#define OOP_INTRO_LINE_H

#include <iostream>
#include <cmath>
#include "Point.h"

#define EPSILON 1e-8

class Line
{
public:
    Line(Point p1, Point p2);
    bool parallelWith(Line l);
    bool isEqualTo(Line l);
    Point intersectWith(Line l);

    void setSlope(Point p1, Point p2);
    double getSlope();

    ~Line();

private:
    Point p1, p2;
    double m; // slope (angular coefficient)
};

#endif //OOP_INTRO_LINE_H
