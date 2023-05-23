#include <iostream>
#include "Line.h"
#include "Point.h"

int main()
{
    double x, y;
    Point p1(0, 0), p2(0, 0);
    Line l1(p1, p2), l2(p1, p2);

    std::cout << "---------------------------------------------\n";
    std::cout << "Program to find the intersection of two lines\n";
    std::cout << "---------------------------------------------\n";

    std::cout << "Type in two points of the first line" << std::endl;
    std::cin >> x >> y;
    p1 = Point(x, y);
    std::cin >> x >> y;
    p2 = Point(x, y);
    l1 = Line(p1, p2);

    std::cout << "Type in two points of the second line" << std::endl;
    std::cin >> x >> y;
    p1 = Point(x, y);
    std::cin >> x >> y;
    p2 = Point(x, y);
    l2 = Line(p1, p2);

    if (l1.parallelWith(l2))
    {
        if (l1.isEqualTo(l2))
        {
            std::cout << "The intersection is the line you gave\n";
        }
        else
        {
            std::cout << "There is no intersection\n";
        }
    }
    else
    {
        std::cout << "The intersection is a point\n";
        std::cout << "And its coordinates are: ";
        p1 = l1.intersectWith(l2);
        std::cout << p1.getX() << " " << p1.getY() << "\n";
    }

    return 0;
}
