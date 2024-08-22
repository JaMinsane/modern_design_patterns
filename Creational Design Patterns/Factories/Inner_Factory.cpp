#include <cmath>
#include <iostream>

// do not need this for factory
enum class PointType
{
    cartesian,
    polar
};

class Point
{
    Point(float x, float y) : x(x), y(y) {}

    class PointFactory
    {
        PointFactory() {}
    public:
        static Point NewCartesian(float x, float y)
        {
            return { x,y };
        }
        static Point NewPolar(float r, float theta)
        {
            return{ r * cos(theta), r * sin(theta) };
        }
    };
public:
    float x, y;
    static PointFactory Factory;
    friend std::ostream& operator<<(std::ostream& os, const Point& obj)
    {
        return os
            << "x: " << obj.x
            << " y: " << obj.y;
    }
};

int main()
{
    // will not work
    // Point p{ 1,2 };

    // nope!
    // Point::PointFactory pf;

    // if factory is public, then
    //auto p = Point::PointFactory::NewCartesian(3, 4);

    // at any rate, use this
    auto pp = Point::Factory.NewCartesian(2, 3);
    std::cout << pp << std::endl;

    return 0;
}