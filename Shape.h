#pragma once
#include "raylib.h"
#include <iostream>

class Shape
{
private:
    float* height;
    float* width;
    Color* color;

    Color GenerateColor();
public:
    float getHeight() const;
    float getWidth() const;
    Color getColor() const;

    Shape();
    virtual ~Shape();
};
