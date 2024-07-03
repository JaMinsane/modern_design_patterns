/**
 * We need two tools of c++ to implement the static decorator:
 * 1. Mixin inheritance: This is a way to inherit from a template argument.
 * 2. Perfect forwarding: Preserves the value category (lvalue or rvalue) 
 *    of function arguments when passing them to another function.
 *    It is declared with the T&& syntax and std::forward<T> is also used.
 */

#include <string>
#include <iostream>
#include <vector>
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
    Shape& shape;
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

// mixin inheritance
// note: class, not typename
template <typename T> struct ColoredShape2 : T
{
    static_assert(is_base_of<Shape, T>::value,
        "Template argument must be a Shape");

/*
* This could also be done using concepts in C++20
* 
* template <typename T>
* concept IsShape = is_base_of<Shape, T>::value;
* 
* template <IsShape T> struct ColoredShape2 : T
*/

    string color;

    // just in case you need it 
    ColoredShape2() {}

    template <typename...Args>
    ColoredShape2(const string& color, Args ...args)
        : T(std::forward<Args>(args)...), color{ color }
        // you cannot call base class ctor here
        // b/c you have no idea what it is
    {
    }

    string str() const override
    {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

// c++20
template <typename T>
concept IsShape = is_base_of<Shape, T>::value;

template <IsShape T> struct TransparentShape2 : T
{
    uint8_t transparency;

    template<typename...Args>
    TransparentShape2(const uint8_t transparency, Args ...args)
        : T(std::forward<Args>(args)...), transparency{ transparency }
    {
    }

    string str() const override
    {
        ostringstream oss;
        oss << T::str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << "% transparency";
        return oss.str();
    }
};

int main()
{
    // mixin inheritance
    ColoredShape2<Circle> green_circle{ "green", 5 };
    green_circle.radius = 123;
    green_circle.resize(2.0f); // Previously in the dynamic decorator this was not possible
    cout << green_circle.str() << endl;

    TransparentShape2<ColoredShape2<Square>> blue_invisible_square{ 0 };
    blue_invisible_square.color = "blue";
    blue_invisible_square.side = 321;
    cout << blue_invisible_square.str() << endl;

    return 0;
}
