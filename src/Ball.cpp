#include "Ball.hpp"
#include "raylib.h"
#include "iostream"

Ball::Ball()
{
    position = {GetScreenHeight() / 2.0f, GetScreenHeight() / 2.0f};
    speed = {300.0f, 300.0f};
    width = 10.0f;
    height = 10.0f;
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