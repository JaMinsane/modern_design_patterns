#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;

    Circle() {}

    explicit Circle(const float radius)
        : radius{ radius }
    {
    }

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override
    {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape
{
    float side;

    Square() {}

    explicit Square(const float side)
        : side{ side }
    {
    }

    string str() const override
    {
        ostringstream oss;
        oss << "A square of with side " << side;
        return oss.str();
    }
};

// we are not changing the base class of existing
// objects
// cannot make, e.g., ColoredSquare, ColoredCircle, etc.

struct ColoredShape : Shape
{
    Shape& shape; // this is now a reference!
    string color;

    ColoredShape(Shape& shape, const string& color)
        : shape{ shape },
        color{ color }
    {
    }

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;


    TransparentShape(Shape& shape, const uint8_t transparency)
        : shape{ shape },
        transparency{ transparency }
    {
    }

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << "% transparency";
        return oss.str();
    }
};

int main()
{
    Square square{ 5 };
    ColoredShape red_square{ square, "red" };
    cout << square.str() << endl;
    cout << red_square.str() << endl;

    TransparentShape my_square{ red_square, 51 }; // It is possible to combine decorators together
    cout << my_square.str() << endl;

    Circle circle{ 2 };
    ColoredShape green_circle{ circle, "green" };
    cout << circle.str() << endl;
    cout << green_circle.str() << endl;
    // green_circle.resize(2); // This will not work, this is a limitation of the dynamic decorator

    return 0;
}
