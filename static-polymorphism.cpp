#include <iostream>
#include <math.h>
const double pi = std::atan(1) * 4;

struct Point
{
    float x, y;
};

class Circle
{
    float _radius;

public:
    Circle(float radius) : _radius{radius} {}
    double area() const { return pi * _radius * _radius; }
};

class Rectangle
{
    Point _corners[2];

public:
    Rectangle(Point const &corner1, Point const &corner2) : _corners{corner1, corner2} {}
    int area() const { return std::abs(_corners[1].x - _corners[0].x) *
                              std::abs(_corners[1].y - _corners[0].y); }
};

template <typename T>
void show_area(T const *pShape)
{
    std::cout << "Area: " << pShape->area() << std::endl;
    auto twoTimes = pShape->area() * 2;
    std::cout << "If you double the area, it would be: " << twoTimes << std::endl;
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
