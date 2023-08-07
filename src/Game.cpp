#include <Game.hpp>
#include <cmath>

Game::Game()
    : ball(),
      paddle()
{
    running = true;
}


void Game::ManageCollisionBallWall()
{
    if (ball.GetRectangle().x < 0.0) 
    {
        gameOver = true;
        ClearBackground(BLACK);
        DrawText("GAME OVER", GetScreenWidth()/2 - 10, GetScreenHeight() / 2 - 10, 50, YELLOW);
    } 
    else if (ball.GetRectangle().x > GetScreenWidth() - ball.GetRectangle().width) 
    {
        gameOver = true;
        ClearBackground(BLACK);
        DrawText("GAME OVER", GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 10, 50, YELLOW);
    };
    if (ball.GetRectangle().y < 0) 
    {
        ball.SetYPosition(0.0);
        ball.SetYSpeed(-1 * ball.GetSpeed().y);
    }
    else if (ball.GetRectangle().y > GetScreenHeight() - ball.GetRectangle().height) 
    {
        ball.SetYPosition(GetScreenHeight() - ball.GetRectangle().height);
        ball.SetYSpeed(-1 * ball.GetSpeed().y);
    };
}

void Game::ManageCollisionBallPaddle()
{
    if (CheckCollisionRecs(ball.GetRectangle(), paddle.GetRectangle()))
    {
        if (ball.GetSpeed().x < 0) //prevent the ball from boncing inside the paddle
        {
            ball.SetXSpeed(-1 * ball.GetSpeed().x);
            if (ball.GetRectangle().y - paddle.GetRectangle().y < paddle.GetRectangle().height / 2) 
            {
                ball.SetYSpeed(-10 * abs(ball.GetRectangle().y - paddle.GetRectangle().y - paddle.GetRectangle().height / 2));
            }
            else 
            {
                ball.SetYSpeed(10 * abs(ball.GetRectangle().y - paddle.GetRectangle().y - paddle.GetRectangle().height / 2));
            }
        };
    };
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
