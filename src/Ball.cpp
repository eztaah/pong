#include "Ball.hpp"
#include "raylib.h"
#include "iostream"

Ball::Ball()
{
    position = {GetScreenWidth() / 2.0, GetScreenHeight() / 2.0};
    speed = {300.0, 300.0};
    width = 10.0;
    height = 10.0;
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



// Encapsulation
Rectangle Ball::GetRectangle() { return {position.x, position.y, width, height}; }

Vector2 Ball::GetSpeed() { return speed; }

void Ball::SetXPosition(float x) { position.x = x; }

void Ball::SetYPosition(float y) { position.y = y; }

void Ball::SetXSpeed(float x) { speed.x = x; }

void Ball::SetYSpeed(float y) { speed.y = y; }