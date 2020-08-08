#include <iostream>
#include <math.h>
const double pi = std::atan(1) * 4;

struct Point
{
    double x, y;
};

class Shape
{
public:
    virtual double area() const = 0;
};

class Circle : public Shape
{
    Point _center;
    double _radius;

public:
    Circle(Point const &center, double radius) : _center{center}, _radius{radius} {}
    double area() const override { return pi * _radius * _radius; }
};

class Rectangle : public Shape
{
    Point _corners[2];

public:
    Rectangle(Point const &corner1, Point const &corner2) : _corners{corner1, corner2} {}
    double area() const override { return std::abs(_corners[1].x - _corners[0].x) *
                                          std::abs(_corners[1].y - _corners[0].y); }
};

int main()
{
    Circle c({10, 10}, 10);
    std::cout << "Circle area: " << c.area() << std::endl;
    Rectangle r({10, 10}, {30, 30});
    std::cout << "Rectangle area: " << r.area() << std::endl;

    return 0;
}
