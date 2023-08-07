#include <Game.hpp>

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
        ball.SetXPosition(0.0);
        ball.SetXSpeed(-1 * ball.GetSpeed().x);
    } 
    else if (ball.GetRectangle().x > GetScreenWidth() - ball.GetRectangle().width) 
    {
        ball.SetXPosition(GetScreenWidth() - ball.GetRectangle().width);
        ball.SetXSpeed(-1 * ball.GetSpeed().x);
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

void ManageCollisionBallPaddle()
{

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