#include "game.hpp"
#include <cmath>
#include <string>


Game::Game()
{
    ball = Ball();      // Initialize the ball
    paddle1 = Paddle(30.0f);        // Initialize the left paddle
    paddle2 = Paddle(GetScreenWidth() - 30.0f);     // Initialize the right paddle
    running = true;
    score = 0;
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
        if (IsKeyDown(KEY_SPACE))    // If the game is not running and the space key is pressed
        {
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

    std::string scoreStr = std::to_string(score);   // Convert score to a string
    DrawText(scoreStr.c_str(), 670, 20, 40, WHITE); 

    if(running)
    {
        ball.Draw();
    } else {
        DrawText("PRESS SPACE TO RESTART", (GetScreenWidth() / 2.0f) - 290.0f, (GetScreenHeight() / 2.0f) - 10.0f, 40, YELLOW);
    }

    EndDrawing();
}


void Game::ManageCollisionBallWall()
{
    if (ball.GetRectangle().x < 0.0)
    {
        running = false;    // Game over
    } 
    else if (ball.GetRectangle().x > GetScreenWidth() - ball.GetRectangle().width) 
    {
        running = false;    // Game over
    };
    if (ball.GetRectangle().y < 0)
    {
        ball.SetYPosition(0.0f);    // Prevent bug when the ball go outside the screen
        ball.SetYSpeed(-1 * ball.GetSpeed().y);     // Make the ball bounce
    }
    else if (ball.GetRectangle().y > GetScreenHeight() - ball.GetRectangle().height) 
    {
        ball.SetYPosition(GetScreenHeight() - ball.GetRectangle().height);  // Prevent bug when the ball go outside the screen
        ball.SetYSpeed(-1 * ball.GetSpeed().y);     // Make the ball bounce
    };
}


void Game::ManageCollisionBallPaddle()
{
    // Paddle 1 collisions
    if (ball.GetSpeed().x < 0)      //prevent the ball from boncing inside the paddle
    {
        if (CheckCollisionRecs(ball.GetRectangle(), paddle1.GetRectangle()))
        {
            ball.SetXSpeed(-1 * ball.GetSpeed().x);     // Make the ball bounce
            score++;
            ball.SetXSpeed(ball.GetSpeed().x + 100.0f);     // Increase the speed of the ball
            ball.SetYSpeed(ball.GetSpeed().y + 100.0f);
        };
    }

    // Paddle 2 collision
    else 
    {
        if (CheckCollisionRecs(ball.GetRectangle(), paddle2.GetRectangle()))
        {
            ball.SetXSpeed(-1 * ball.GetSpeed().x);     // Make the ball bounce
            score++;
            ball.SetXSpeed(ball.GetSpeed().x - 100.0f);     // Increase the speed of the ball
            ball.SetYSpeed(ball.GetSpeed().y - 100.0f);
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
    score = 0;
}