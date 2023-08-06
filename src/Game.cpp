<<<<<<< Updated upstream
#include <Game.hpp>

=======
#include "../include/Game.hpp"
#include <iostream>
>>>>>>> Stashed changes

Game::Game()
{
    InitWindow(1366, 768, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    ball = Ball();
    paddle = Paddle();
}


void Game::Update()
{
    ManageCollisionBallWall();
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


void Game::ManageCollisionBallWall()
{
    if (ball.position.x < 0.0) {
        ball.position.x = 0.0;
        ball.speed.x *= -1;
    } else if (ball.position.x > GetScreenWidth() - ball.width) {
        ball.position.x = GetScreenWidth() - ball.width;
        ball.speed.x *= -1;
    };
    if (ball.position.y < 0) {
        ball.position.y = 0;
        ball.speed.y *= -1;
    }
    else if (ball.position.y > GetScreenHeight() - ball.height) {
        ball.position.y = GetScreenHeight() - ball.height;
        ball.speed.y *= -1;
    };
}
