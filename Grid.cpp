#include "Grid.h"
#include <vector>

void Grid::Draw()
{
    for (size_t i = 0; i < m_grid.to_string().length(); i++)
    {
        if (m_grid.to_string()[i] == '1')
        {
            DrawRectangle((i % 10) * width, (i / 10) * height, width, height, color);
        }
    }
}

void Grid::Draw(const Figure& figure)
{
    Draw();

    figure.Draw();
}

void Grid::Push(const Vector2* figure, const unsigned int&& size)
{
    std::cout << "Object Pushing" << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "index: " << 219 - (figure[i].x/20 + figure[i].y/20 * 10) << std::endl;
        if (!m_grid.test(219 - (figure[i].x/20 + figure[i].y/20 * 10)))
        {
            m_grid.flip(219 - (figure[i].x/20 + figure[i].y/20 * 10));
        }
    }
    std::cout << "Push is Completed" << std::endl;
}

bool Grid::Collision(const Vector2* figure, const unsigned int&& size, const float&& y)
{
    if (y == 420)
    {
        return false;
    }
    
    for (unsigned int i = 0; i < size; i++)
    {
        int x{(int)figure[i].x}, y{(int)figure[i].y};

        if (m_grid.test(209 - (x/20 + y/20 * 10)) == 1)
        {
            return false;
        }
    }
    return true;
}

int Grid::DestroyLine()
{
    int count_completed_line{};

    // Lambda capture
    auto Check = [&](int index)
	{
		return m_grid.test(index) == 1 ? true : false;
	};

    std::vector<int> index;
    int count_true{};

    for (unsigned int i = 0; i < m_grid.size(); i++)
    {
        if (i % 10 == 0)
        {
            if (count_true == 10)
            {
                index.push_back(i);
                for (int j = 0; j < count_true; j++)
                {
                    m_grid.flip(i - j - 1);
                }
                count_completed_line++;
            }

            count_true = 0;
            count_true += Check(i);
        }
        else
        {
            count_true += Check(i);
        }
    }

    for (const auto &i : index)
    {
        std::cout << "index:" << i << std::endl;
    }

    for (int j = index.size() - 1; j >= 0; j--)
    {
        for (int i = index[j]; i < 220; i++)
        {
            if (m_grid.test(i) == 1)
            {
                m_grid.flip(i);
                m_grid.flip(i - 10);
            }
        }
    }

    return count_completed_line * 500;
}

bool Grid::LeftCollision(const Vector2* figure, const unsigned int&& size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        int x{(int)figure[i].x}, y{(int)figure[i].y};
        if (((220 - (x/20 + y/20 * 10)) / 10) < ((219 - (x/20 + y/20 * 10)) / 10))
        {
            continue;
        }

        if (m_grid.test(220 - (x/20 + y/20 * 10)) == 1)
        {
            return false;
        }
    }

    return true;
}

bool Grid::RightCollision(const Vector2* figure, const unsigned int&& size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        int x{(int)figure[i].x}, y{(int)figure[i].y};
        if (((218 - (x/20 + y/20 * 10)) / 10) < ((219 - (x/20 + y/20 * 10)) / 10))
        {
            continue;
        }

        if (m_grid.test(218 - (x/20 + y/20 * 10)) == 1)
        {
            return false;
        }
    }
    
    return true;
}

bool Grid::CheckEndGame()
{
    for (unsigned int i = 200; i < 220; i++)
    {
        if (m_grid.test(i) == 1)
        {
            return true;
        }
    }
    return false;
}

Grid::Grid() : width(20), height(20), color(SKYBLUE)
{ }

Grid::~Grid()
{

}