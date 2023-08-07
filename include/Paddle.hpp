#pragma once
#include "raylib.h"

class Paddle
{
    public:
        Paddle();
        void Update();
        void Draw();

        //Encpasulation
        Rectangle GetRectangle();

    private:
        Vector2 position;
        Vector2 midpoint;
        float speed;
        float height;
        float width;
};