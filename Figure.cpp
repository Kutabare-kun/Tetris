#include "Figure.h"

/*
*   Figure 1: 0000
*
*   Figure 2: 0
*             000
*
*   Figure 3:   0
*             000
*
*   Figure 4: 00
*             00
*
*   Figure 5:  00
*             00
*
*   Figure 6:  0
*             000
*
*   Figure 7: 00
*              00   
*/
Vector2* Figure::GenerateFigure()
{
    Vector2* figure{new Vector2[size]};

    switch (type)
    {
    case 1:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 0.0};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }
        }
        break;
    case 2:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 0.0};
            }
            else if (i == 1)
            {
                figure[i] = {figure[i-1].x, figure[i-1].y + getHeight()};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }
        }        
        break;
    case 3:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {40.0, 0.0};
            }
            else if (i == 1)
            {
                figure[i] = {figure[i-1].x, figure[i-1].y + getHeight()};
            }
            else
            {
                figure[i] = {figure[i-1].x - getWidth(), figure[i-1].y};
            }            
        }
        break;
    case 4:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 0.0};
            }
            else if (i == 2)
            {
                figure[i] = {figure[i-1].x, figure[i-1].y + getHeight()};
            }
            else if (i == 3)
            {
                figure[i] = {figure[i-1].x - getWidth(), figure[i-1].y};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }            
        }        
        break;
    case 5:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 20.0};
            }
            else if (i == 2)
            {
                figure[i] = {figure[i-1].x, figure[i-1].y - getHeight()};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }            
        }          
        break;
    case 6:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 20.0};
            }
            else if (i == 3)
            {
                figure[i] = {figure[1].x, figure[1].y - getHeight()};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }            
        }         
        break;
    case 7:
        for (unsigned int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                figure[i] = {0.0, 0.0};
            }
            else if (i == 2)
            {
                figure[i] = {figure[1].x, figure[1].y + getHeight()};
            }
            else
            {
                figure[i] = {figure[i-1].x + getWidth(), figure[i-1].y};
            }            
        }          
        break;
    default: break;
    }
    return figure;
}

Vector2* Figure::getFigure() const
{
    return m_figure;
}

unsigned int Figure::getSize() const
{
    return size;
}

void Figure::Draw() const
{
    for (unsigned int i = 0; i < size; i++)
    {
        DrawRectangle(m_figure[i].x, m_figure[i].y, getWidth(), getHeight(), getColor());
    }
}

void Figure::RotateFigure(time_t& cooldown)
{
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S))
    {
        switch (type)
        {
        case 1:
            if (rotate == 0)
            {
                m_figure[0] = {m_figure[1].x, m_figure[1].y - this->getHeight()};
                m_figure[2] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                m_figure[3] = {m_figure[2].x, m_figure[2].y + this->getHeight()};
                rotate++;
            }
            else
            {
                m_figure[0] = {m_figure[1].x - this->getWidth(), m_figure[1].y};
                m_figure[2] = {m_figure[1].x + this->getWidth(), m_figure[1].y};
                m_figure[3] = {m_figure[2].x + this->getWidth(), m_figure[1].y};
                rotate--;
            }
            break;
        case 2:
            if (rotate == 0)
            {
                m_figure[2] = {m_figure[0].x + this->getWidth(), m_figure[0].y};
                m_figure[3] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                rotate++;
            }
            else if (rotate == 1)
            {
                m_figure[1] = {m_figure[2].x + this->getWidth(), m_figure[2].y};
                m_figure[3] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                rotate++;
            }
            else if (rotate == 2)
            {
                m_figure[0] = {m_figure[1].x, m_figure[1].y - this->getHeight()};
                m_figure[3] = {m_figure[0].x, m_figure[0].y - this->getHeight()};
                rotate++;
            }
            else
            {
                m_figure[2] = {m_figure[1].x + this->getWidth(), m_figure[1].y};
                m_figure[3] = {m_figure[2].x + this->getWidth(), m_figure[2].y};
                rotate = 0;
            }
            break;
        case 3:
            if (rotate == 0)
            {
                m_figure[2] = {m_figure[1].x, m_figure[1].y + this->getWidth()};
                m_figure[3] = {m_figure[2].x + this->getHeight(), m_figure[2].y};
                rotate++;
            }
            else if (rotate == 1)
            {
                m_figure[2] = {m_figure[0].x + this->getWidth(), m_figure[0].y};
                m_figure[3] = {m_figure[2].x + this->getWidth(), m_figure[2].y};
                rotate++;
            }
            else if (rotate == 2)
            {
                m_figure[2] = {m_figure[0].x - this->getWidth(), m_figure[0].y};
                m_figure[3] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                rotate++;
            }
            else
            {
                m_figure[2].y += this->getHeight();
                m_figure[3] = {m_figure[2].x - this->getWidth(), m_figure[2].y};
                rotate = 0;
            }            
            break;
        case 5:
            if (rotate == 0)
            {
                m_figure[0] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                m_figure[2] = {m_figure[1].x - this->getWidth(), m_figure[1].y};
                m_figure[3] = {m_figure[2].x, m_figure[2].y - this->getHeight()};
                rotate++;
            }
            else
            {
                m_figure[0] = {m_figure[1].x - this->getWidth(), m_figure[1].y};
                m_figure[2] = {m_figure[1].x, m_figure[1].y - this->getWidth()};
                m_figure[3] = {m_figure[2].x + this->getWidth(), m_figure[2].y};
                rotate--;
            }            
            break;
        case 6:
            if (rotate == 0)
            {
                m_figure[0] = {m_figure[1].x, m_figure[1].y + this->getHeight()};
                rotate++;
            }
            else if (rotate == 1)
            {
                m_figure[3] = m_figure[0];
                m_figure[0] = {m_figure[1].x - this->getWidth(), m_figure[1].y};
                rotate++;
            }
            else if (rotate == 2)
            {
                m_figure[2] = m_figure[3];
                m_figure[3].y = m_figure[0].y - this->getHeight();
                rotate++;
            }
            else
            {
                m_figure[2] = {m_figure[1].x + this->getWidth(), m_figure[1].y};
                rotate = 0;
            }              
            break;
        case 7:
            if (rotate == 0)
            {
                m_figure[0].y += this->getHeight();
                m_figure[3] = {m_figure[0].x, m_figure[0].y + this->getHeight()};
                rotate++;
            }
            else
            {
                m_figure[0].y -= this->getHeight();
                m_figure[3] = {m_figure[2].x + this->getWidth(), m_figure[2].y};
                rotate--;
            }             
            break;
        
        default:
            break;
        }

        cooldown = time(NULL) + 0.1;
    }
}

void Figure::Falling()
{
    for (unsigned int i = 0; i < size; i++)
    {
        m_figure[i].y += getHeight();
    }
}

void Figure::MoveLeft()
{
    for (unsigned int i = 0; i < size; i++)
    {
        m_figure[i].x -= getHeight();
    }
}

void Figure::MoveRight()
{
    for (unsigned int i = 0; i < size; i++)
    {
        m_figure[i].x += getHeight();
    }
}

Vector2 Figure::getLeft() const
{
    Vector2 shape{ m_figure[0] };
    for (size_t i = 1; i < size; i++)
    {
        if (shape.x >= m_figure[i].x)
        {
            shape = m_figure[i];
        }
    }
    return shape;
}

Vector2 Figure::getTop() const
{
    Vector2 shape{ m_figure[0] };
    for (size_t i = 1; i < size; i++)
    {
        if (shape.y >= m_figure[i].y)
        {
            shape = m_figure[i];
        }
    }
    return shape;
}

Vector2 Figure::getRight() const
{
    Vector2 shape{ m_figure[0] };
    for (size_t i = 1; i < size; i++)
    {
        if (shape.x <= m_figure[i].x)
        {
            shape = m_figure[i];
        }
    }
    return shape;
}

Vector2 Figure::getBottom() const
{
    Vector2 shape{ m_figure[0] };
    for (size_t i = 1; i < size; i++)
    {
        if (shape.y <= m_figure[i].y)
        {
            shape = m_figure[i];
        }
    }
    return shape;
}

Figure::Figure() : size(4), type(GetRandomValue(1, 7)), m_figure(GenerateFigure())
{ }

Figure::~Figure()
{
    delete m_figure;
    std::cout << "~Figure" << std::endl;
}
