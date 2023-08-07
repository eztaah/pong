#include "Paddle.hpp"
#include "raylib.h"


Paddle::Paddle() {}


Paddle::Paddle(float x)
{
    position.x = x;
    position.y = (GetScreenHeight() / 2.0f) - width / 2.0f;
    speed = 10.0f;
    width = 10.0f;
    height = 70.0f;
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