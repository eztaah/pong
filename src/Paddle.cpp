#include "paddle.hpp"
#include <raylib.hpp>


Paddle::Paddle() {}


Paddle::Paddle(float x_)
{
    position.x = x_;
    position.y = (GetScreenHeight() / 2.0f) - (height / 2.0f);
    speed = 10.0f;
    width = 10.0f;
    height = 70.0f;
}


void Paddle::Update()
{
    // move paddle
    if (IsKeyDown(KEY_W)) {
        position.y -= 600.0 * GetFrameTime();
    };
    if (IsKeyDown(KEY_S)) {
        position.y += 600.0 * GetFrameTime();
    };
}


void Paddle::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, BLUE);
}


Rectangle Paddle::GetRectangle() 
{
    return {position.x, position.y, width, height};
}


void Paddle::SetXPosition(float x_) 
{
    position.x = x_;
}


void Paddle::SetYPosition(float y_)
{
    position.y = y_;
}