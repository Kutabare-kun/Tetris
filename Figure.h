#pragma once
#include <ctime>
#include "Shape.h"

class Figure : public Shape
{
private:
    const unsigned int size;
    const int type;
    Vector2* m_figure;
    int rotate{};

    Vector2* GenerateFigure();
public:
    Vector2* getFigure() const;
    unsigned int getSize() const;
    Vector2 getLeft() const;
    Vector2 getTop() const;
    Vector2 getRight() const;
    Vector2 getBottom() const;

    void Draw() const;
    void RotateFigure(time_t& cooldown);
    void Falling();
    void MoveLeft();
    void MoveRight();

    Figure();
    ~Figure();
};
