#pragma once
#include "raylib.h"

class Ball
{
public:
    Ball();
    void Draw();
    void Update();

    Vector2 position;
    Vector2 midpoint;
    Vector2 speed;
    int width;
    int height;

private:

};