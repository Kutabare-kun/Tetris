#include "Shape.h"

Color Shape::GenerateColor()
{
    switch (GetRandomValue(1, 5))
    {
    case 1: return RED;
    case 2: return ORANGE;
    case 3: return PURPLE;
    case 4: return BLUE;
    case 5: return LIME;
    default: break;
    }
    return WHITE;
}

float Shape::getHeight() const
{
    return *height;
}

float Shape::getWidth() const
{
    return *width;
}

Color Shape::getColor() const
{
    return *color;
}

Shape::Shape() 
    : height(new float{20.0}), width(new float{20.0}), color(new Color{GenerateColor()})
{ }

Shape::~Shape()
{
    delete height;
    delete width;
    delete color;
    std::cout << "~Shape" << std::endl;
}