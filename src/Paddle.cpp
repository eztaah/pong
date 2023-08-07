#include "Paddle.hpp"
#include "raylib.h"

Paddle::Paddle()
{
    position.x = GetScreenWidth() - 30.0;
    position.y = (GetScreenHeight() / 2.0) - width / 2.0;
	width = 10;
	height = 70;
    speed = 10;

    midpoint.x = position.x + width / 2;
    midpoint.y = position.y + height / 2;
}


void Paddle::Update()
{
    // move paddle
    if (IsKeyDown(KEY_W)) {
        position.y -= 600.0 * GetFrameTime();
        midpoint.y = position.y + height / 2;
    };
    if (IsKeyDown(KEY_S)) {
        position.y += 600.0 * GetFrameTime();
        midpoint.y = position.y + height / 2;
    };
}


void Paddle::Draw()
{
    DrawRectangle(position.x, position.y, width, height, BLUE);
}


// Encapsulation
Rectangle Paddle::GetRectangle()
{
    return {position.x, position.y, width, height};
}