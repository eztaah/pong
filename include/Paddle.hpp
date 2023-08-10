#pragma once
#include <raylib.hpp>

class Paddle
{
    public:
        Paddle();
        Paddle(float x);
        void Update();
        void Draw() const;

        Rectangle GetRectangle();
        void SetXPosition(float x);
        void SetYPosition(float y);

    private:
        Vector2 position;
        float speed;
        float height;
        float width;
};