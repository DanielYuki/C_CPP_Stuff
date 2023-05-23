#include "Point.h"

Point::Point(double coordX, double coordY)
{
    x = coordX;
    y = coordY;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

Point::~Point()
{
    //    std::cout << "Destroy Point \n";
}