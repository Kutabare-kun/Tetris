#pragma once
#include <bitset>
#include <string>
#include "Figure.h"

struct Line
{
    Vector2 start;
    Vector2 end;
    Color color;
};

class Grid
{
private:
    int width;
    int height;
    Color color;
    std::bitset<220> m_grid;
public:
    void Draw();
    void Draw(const Figure& figure);

    void Push(const Vector2* figure, const unsigned int&& size);
    bool Collision(const Vector2* figure, const unsigned int&& size, const float&& y);
    int DestroyLine();

    bool LeftCollision(const Vector2* figure, const unsigned int&& size);
    bool RightCollision(const Vector2* figure, const unsigned int&& size);

    bool CheckEndGame();

    Grid();
    ~Grid();
};
