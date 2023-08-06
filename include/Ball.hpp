#pragma once
#include <raylib.h>

class Ball
{
public:
    Ball();
    void Draw();
    void Update();

private:
    Vector2 position;
    Vector2 speed;
    bool CollidesWithHorizontalBorder();
    bool CollidesWithTopHorizontalBorder();
    bool CollidesWithBottomHorizontalBorder();
    void reverseYSpeed();
    void pullOutBall();
};