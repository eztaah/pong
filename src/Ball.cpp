#include "Ball.hpp"
#include "raylib.h"
#include "iostream"

Ball::Ball()
{
    position.x = GetScreenWidth() / 2;
    position.y = GetScreenHeight() / 2;

    speed.x = 500;
    speed.y = 500;
}


void Ball::Draw()
{
    DrawRectangle(position.x, position.y, 5, 5, RED);
}


void Ball::Update()
{
    if(CollidesWithHorizontalBorder())
    {
        reverseYSpeed();
        pullOutBall();
    }
    else 
    {
        position.x += speed.x * GetFrameTime();
        position.y += speed.y * GetFrameTime();
    }
}


bool Ball::CollidesWithHorizontalBorder()
{
    if(position.y > (GetScreenHeight() - 15) || position.y < 10)
       return true;

    return false;
}


void Ball::reverseYSpeed()
{
    speed.y = - speed.y;
}

void Ball::pullOutBall()
{
    if(CollidesWithBottomHorizontalBorder())
    {
        position.y = GetScreenHeight() - 15;
        std::cout << "o";
    }
    else if(CollidesWithTopHorizontalBorder())
    {
        position.y = 11;
    }
}

bool Ball::CollidesWithBottomHorizontalBorder()
{
    if(position.y > (GetScreenHeight() - 15))
        return true;

    return false;
}

bool Ball::CollidesWithTopHorizontalBorder()
{
    if(position.y < 10)
        return true;

    return false;
}