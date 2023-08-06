#include <Paddle.hpp>
#include <raylib.h>

Paddle::Paddle()
{
    position.x = GetScreenWidth() - 30.0;
    position.y = (GetScreenHeight() / 2.0) - width / 2.0;
	width = 10;
	height = 70;
    speed = 10;
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