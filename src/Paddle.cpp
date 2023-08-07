#include <Paddle.hpp>
#include <raylib.h>

Paddle::Paddle()
{
    position = {30.0f, (GetScreenHeight() / 2.0f) - width / 2.0f};
    speed = 10.0f;
	width = 10.0f;
	height = 70.0f;
}


void Paddle::Update()
{
    // move paddle
    if (IsKeyDown(KEY_W)) {
        position.y -= 600.0 * GetFrameTime();
    };
    if (IsKeyDown(KEY_S)) {
        position.y += 600.0 * GetFrameTime();
    };
}


void Paddle::Draw()
{
    DrawRectangle(position.x, position.y, width, height, BLUE);
}


// Encapsulation
Rectangle Paddle::GetRectangle()
{
    return {position.x, position.y, width, height};
}