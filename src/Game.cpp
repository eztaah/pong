#include <Game.hpp>


Game::Game()
{
    InitWindow(1366, 768, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    ball = Ball();
    paddle = Paddle();
}


void Game::Update()
{
    ball.Update();
    paddle.Update();
}


void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    ball.Draw();
    paddle.Draw();
    EndDrawing();
}
