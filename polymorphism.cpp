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
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Circle : public Shape
{
    double _radius;

public:
    Circle(double radius) : _radius{radius} {}
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

void show_area(Shape const *pShape)
{
    std::cout << "Area: " << pShape->area() << std::endl;
}

int main()
{
    Circle c(10);

    Rectangle r({10, 10}, {30, 30});

    std::cout << "Circle area: ";
    show_area(&c);
    std::cout << "Rectangle area: ";
    show_area(&r);

    return 0;
}
