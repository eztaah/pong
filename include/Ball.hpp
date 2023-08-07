#pragma once
#include <raylib.h>

class Ball
{
public:
    Ball();
    void Update();
    void Draw();

    // Encapsulation
    Rectangle GetRectangle();
    Vector2 GetSpeed();
    void SetXPosition(float x);
    void SetYPosition(float y);
    void SetXSpeed(float x);
    void SetYSpeed(float y);

private:
    Vector2 position;
    Vector2 speed;
    Vector2 midpoint;
    float width;
    float height;
};