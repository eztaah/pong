#include "ball.hpp"
#include <raylib.hpp>
#include <iostream>

Ball::Ball()
{
    position = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    speed = {300.0f, 300.0f};
    width = 10.0f;
    height = 10.0f;
}


void Ball::Update()
{
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();
}


void Ball::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, RED);
}


Rectangle Ball::GetRectangle()
{
    return {position.x, position.y, width, height};
}


Vector2 Ball::GetSpeed() 
{
    return speed;
}


void Ball::SetXPosition(float x_) 
{
    position.x = x_;
}


void Ball::SetYPosition(float y_) 
{
    position.y = y_;
}


void Ball::SetXSpeed(float x_) 
{
    speed.x = x_;
}


void Ball::SetYSpeed(float y_) 
{
    speed.y = y_;
}