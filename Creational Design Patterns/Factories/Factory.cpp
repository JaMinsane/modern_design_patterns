#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    /*Point(float a, float b, PointType type = PointType::cartesian)
    {
      if (type == PointType::cartesian)
      {
        x = a; b = y;
      }
      else
      {
        x = a*cos(b);
        y = a*sin(b);
      }
    }*/

    // instead use a factory
public:
    Point(float x, float y) : x(x), y(y) {}
    float x, y;
};

struct PointFactory
{
    static Point NewCartesian(float x, float y)
    {
        return Point{ x,y };
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{ r * cos(theta), r * sin(theta) };
    }
};

int main()
{
	auto p = PointFactory::NewPolar(2, M_PI_4);
    std::cout << p.x << " " << p.y << '\n';

    Point p2{ 3, 4 };
    std::cout << p2.x << " " << p2.y << '\n';
	return 0;
}