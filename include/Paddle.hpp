#pragma once
#include "raylib.h"

class Paddle
{
    public:
        Paddle();
        void Update();
        void Draw();
        Vector2 position;
        Vector2 midpoint;
        float height;
        float width;

    private:
        float speed;
};