#pragma once
#include <raylib.h>

class Paddle
{
    public:
        Paddle();
        void Update();
        void Draw();
        Rectangle GetRectangle();

    private:
        Vector2 position;
        float height;
        float width;
        float speed;
};