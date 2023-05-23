#include "Line.h"

// declaring a line obj
Line::Line(Point point1, Point point2) : p1(point1), p2(point2)
{
    Line::setSlope(point1, point2);
}

// Calculates the angular coefficients (set the slopes)
void Line::setSlope(Point p1, Point p2)
{
    m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
}

double Line::getSlope()
{
    return m;
}

bool Line::parallelWith(Line l)
{
    // Checks if the lines are parallel (m1 is equal to m2)
    return std::abs(getSlope() - l.getSlope()) < EPSILON;
}

bool Line::isEqualTo(Line l)
{
    // Check if both pairs of points are equal (current line is equal to provided line)
    return (p1.getX() == l.p1.getX() && p1.getY() == l.p1.getY() &&
            p2.getX() == l.p2.getX() && p2.getY() == l.p2.getY());
}

Point Line::intersectWith(Line l)
{
    // get slopes
    double slope1 = getSlope();
    double slope2 = l.getSlope();

    // Calculate the y-intercepts of the lines
    double intercept1 = p1.getY() - slope1 * p1.getX();
    double intercept2 = l.p1.getY() - slope2 * l.p1.getX();

    // Calculate the x-coordinate of the intersection point
    double xIntersect = (intercept2 - intercept1) / (slope1 - slope2);

    // Calculate the y-coordinate of the intersection point
    double yIntersect = slope1 * xIntersect + intercept1;

    // Create a Point object for the intersection coordinates and return it
    return Point(xIntersect, yIntersect);
}

Line::~Line()
{
    //    std::cout << "Destroy Line \n";
}