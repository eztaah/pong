#include "Ball.hpp"
#include "raylib.h"
#include "iostream"

Ball::Ball()
{
    position.x = GetScreenWidth() / 2;
    position.y = GetScreenHeight() / 2;

    speed.x = 300.0;
    speed.y = 300.0;

    width = 10;
    height = 10;

    midpoint.x = position.x + width / 2;
    midpoint.y = position.y + height / 2;
}


void Ball::Update()
{
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();
    midpoint.x = position.x + width / 2;
    midpoint.y = position.y + height / 2;
}


void Ball::Draw()
{
    DrawRectangle(position.x, position.y, width, height, RED);
}