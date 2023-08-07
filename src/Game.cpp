#include <Game.hpp>
#include <cmath>

Game::Game()
{
    ball = Ball();
    paddle1 = Paddle(30.0f);
    paddle2 = Paddle(GetScreenWidth() - 30.0f);
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
    // paddle 1
    if (ball.GetSpeed().x < 0) //prevent the ball from boncing inside the paddle
    {
        if (CheckCollisionRecs(ball.GetRectangle(), paddle1.GetRectangle()))
        {
            ball.SetXSpeed(-1 * ball.GetSpeed().x);
            if (ball.GetRectangle().y - paddle1.GetRectangle().y < paddle1.GetRectangle().height / 2) 
            {
                ball.SetYSpeed(-10 * abs(ball.GetRectangle().y - paddle1.GetRectangle().y - paddle1.GetRectangle().height / 2));
            }
            else 
            {
                ball.SetYSpeed(10 * abs(ball.GetRectangle().y - paddle1.GetRectangle().y - paddle1.GetRectangle().height / 2));
            }
        };
    }
    // paddle 2
    else 
    {
        if (CheckCollisionRecs(ball.GetRectangle(), paddle2.GetRectangle()))
        {
            ball.SetXSpeed(-1 * ball.GetSpeed().x);
            if (ball.GetRectangle().y - paddle2.GetRectangle().y < paddle2.GetRectangle().height / 2) 
            {
                ball.SetYSpeed(-10 * abs(ball.GetRectangle().y - paddle2.GetRectangle().y - paddle2.GetRectangle().height / 2));
            }
            else 
            {
                ball.SetYSpeed(10 * abs(ball.GetRectangle().y - paddle2.GetRectangle().y - paddle2.GetRectangle().height / 2));
            }
        };
    };
}


void Game::Update()
{
    ManageCollisionBallWall();
    ManageCollisionBallPaddle();
    ball.Update();
    paddle1.Update();
    paddle2.Update();
}


void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    ball.Draw();
    paddle1.Draw();
    paddle2.Draw();
    EndDrawing();
}
