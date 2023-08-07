#include "Game.hpp"
#include <cmath>

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
    ManageCollisionBallPaddle();
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

void Game::ManageCollisionBallPaddle()
{
    if ((ball.position.x - paddle.position.x) < 0 &&
        (ball.position.x - paddle.position.x) >= -ball.width &&
        (ball.position.y - paddle.position.y) < paddle.height &&
        ball.position.y - paddle.position.y > -ball.height)
    {
        ball.position.x = paddle.position.x - ball.width;
        ball.midpoint.x = ball.position.x + ball.width / 2;
        double tan = (ball.midpoint.y - paddle.midpoint.y) / (ball.midpoint.x - paddle.midpoint.x);
        ball.speed.x = ball.speed.x / abs(ball.speed.x);
        ball.speed.x *= -424 / sqrt(1 + tan * tan * coeff * coeff);
        ball.speed.y = ball.speed.y / abs(ball.speed.y);
        ball.speed.y = -((tan / abs(tan)) * 424) / sqrt(1 + (coeff * coeff) / (tan * tan));
    }
}
