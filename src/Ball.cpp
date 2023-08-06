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
}


void Ball::Update()
{
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();
}


void Ball::Draw()
{
    DrawRectangle(position.x, position.y, width, height, RED);
}