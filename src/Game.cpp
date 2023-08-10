#include "game.hpp"
#include <cmath>


Game::Game()
{
    ball = Ball();
    paddle1 = Paddle(30.0f);
    paddle2 = Paddle(GetScreenWidth() - 30.0f);
    running = true;
}


void Game::Update()
{
    if(running) 
    {
        ManageCollisionBallWall();
        ManageCollisionBallPaddle();
        ball.Update();
        paddle1.Update();
        paddle2.Update();
    } 
    else
    {
        if (IsKeyDown(KEY_SPACE)) {
            Restart();
        }
    }
}


void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    paddle1.Draw();
    paddle2.Draw();

    if(running)
    {
        ball.Draw();
    } else {
        DrawText("PRESS SPACE TO RESTART", (GetScreenWidth() / 2.0f) - 280.0f, (GetScreenHeight() / 2.0f) - 10.0f, 40, YELLOW);
    }

    EndDrawing();
}


void Game::ManageCollisionBallWall()
{
    if (ball.GetRectangle().x < 0.0) 
    {
        running = false;
    } 
    else if (ball.GetRectangle().x > GetScreenWidth() - ball.GetRectangle().width) 
    {
        running = false;
    };
    if (ball.GetRectangle().y < 0)
    {
        ball.SetYPosition(0.0f);
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


void Game::Restart()
{
    ball.SetXPosition(GetScreenWidth() / 2.0f);
    ball.SetYPosition(GetScreenHeight() / 2.0f);
    ball.SetXSpeed(300.0f);
    ball.SetYSpeed(300.0f);
    paddle1.SetXPosition(30.0f);
    paddle1.SetYPosition((GetScreenHeight() / 2.0f) - (paddle1.GetRectangle().height / 2.0f));
    paddle2.SetXPosition(GetScreenWidth() - 30.0f);
    paddle2.SetYPosition((GetScreenHeight() / 2.0f) - (paddle1.GetRectangle().height / 2.0f));

    running = true;
}