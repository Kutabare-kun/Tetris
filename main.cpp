#include "Grid.h"

int main(void)
{
    // Initialization window
    constexpr int window_dimensions[2]{350, 440};
    InitWindow(window_dimensions[0], window_dimensions[1], "Tetris");

    Grid grid;
    Figure* figure = new Figure;

    constexpr Line start_spawn_obj {{0.0, 40.0}, {200.0, 40.0}, DARKPURPLE};
    Rectangle interface{200.0, 0.0, 150, static_cast<float>(window_dimensions[1])};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        const float dT = GetFrameTime();
        static float delay_fall_figure{};
        static float delay_push{};
        static int score{};

        // Cooldown to rotate figure
        static time_t cooldown{};

        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Game Logic
        if (!grid.CheckEndGame())
        {
            if (grid.Collision(figure->getFigure(), figure->getSize(), figure->getBottom().y))
            {
                // Move
                if (IsKeyPressed(KEY_A) 
                    && static_cast<int>(figure->getLeft().x) > 0
                    && grid.LeftCollision(figure->getFigure(), figure->getSize()))
                {
                    figure->MoveLeft();
                }
                else if (IsKeyPressed(KEY_D) 
                        && static_cast<int>(figure->getRight().x) < 180
                        && grid.RightCollision(figure->getFigure(), figure->getSize()))
                {
                    figure->MoveRight();
                }

                // Rotate Figure
                if (cooldown < time(NULL))
                {
                    figure->RotateFigure(cooldown);
                }

                // Falling figure
                if (delay_fall_figure >= 20)
                {
                    figure->Falling();
                    delay_fall_figure = 0;
                }
                else
                {
                    delay_fall_figure += 60 * dT;
                }   

                delay_push = 0.0;     
            }
            else
            {
                if (delay_push > 1.0)
                {
                    // Push figure to grid
                    grid.Push(figure->getFigure(), std::move(figure->getSize()));
                    delete figure;
                    figure = nullptr;
                    figure = new Figure;

                    delay_push = 0.0;
                }
                else
                {
                    // Move
                    if (IsKeyPressed(KEY_A) 
                        && static_cast<int>(figure->getLeft().x) > 0
                        && grid.LeftCollision(figure->getFigure(), figure->getSize()))
                    {
                        figure->MoveLeft();
                    }
                    else if (IsKeyPressed(KEY_D) 
                            && static_cast<int>(figure->getRight().x) < 180
                            && grid.RightCollision(figure->getFigure(), figure->getSize()))
                    {
                        figure->MoveRight();
                    }

                    delay_push += 1 * dT;
                }
            }

            // Draw grid with figure
            grid.Draw(*figure);

            // Draw Interface
            DrawRectangle(interface.x, interface.y, interface.width, interface.height, start_spawn_obj.color);

            // An object is created at the top of this line
            DrawLine(start_spawn_obj.start.x, start_spawn_obj.start.y,
                    start_spawn_obj.end.x, start_spawn_obj.end.y,
                    start_spawn_obj.color);
        }
        else
        {
            // Draw Interface
            DrawRectangle(interface.x, interface.y, interface.width, interface.height, start_spawn_obj.color);

            // An object is created at the top of this line
            DrawLine(start_spawn_obj.start.x, start_spawn_obj.start.y,
                    start_spawn_obj.end.x, start_spawn_obj.end.y,
                    start_spawn_obj.color);

            DrawText("GAME OVER", 215, 220, 20, RED);
        }

        // Check if each box in line be true --> destroy --> get score
        score += grid.DestroyLine();

        // Draw Score
        DrawText("SCORE", 215, 5, 20, RED);
        DrawText(std::to_string(score).c_str(), 215, 25, 20, RED);

        // End drawing
        EndDrawing();
    }
    CloseWindow();
}
