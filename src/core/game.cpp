#include "game.hpp"
#include <string>


///////////////// PUBLIC /////////////////
Game::Game()
    : _ball(),
      _paddle1(30.0f),
      _paddle2(GetScreenWidth() - 30.0f),
      _isGameOver(false),
      _score(0)
{}

void Game::Update()
{
    if(!_isGameOver)    // If the game is running
    {
        _HandleInputs();    // Get keys pressed and update paddle1 position
        _ball.Update();     // Update ball position

        _HandleCollisions();    // Manage collisions between ball-boundary and ball-paddles
    } 
    else    // If the game is not running
    {
        if (IsKeyDown(KEY_SPACE))    // If the game is not running and the space key is pressed
            _Restart();   // Setup a new game
    }
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(WHITE);

    // === Draw entities ===
    _paddle1.Render();
    _paddle2.Render();
    if(!_isGameOver)
        _ball.Render();

    // === Draw score ===
    std::string scoreStr = std::to_string(_score);   // Convert score to a string
    DrawText(scoreStr.c_str(), 670, 20, 40, BLACK);     // Display the score

    // === Draw restart message (if game over)===
    if(_isGameOver)
        DrawText("PRESS SPACE TO RESTART", (GetScreenWidth() / 2.0f) - 290.0f, (GetScreenHeight() / 2.0f) - 10.0f, 40, GRAY);

    EndDrawing();
}


///////////////// PRIVATE /////////////////
void Game::_HandleInputs()
{
    if (IsKeyDown(KEY_W))   // Raylib assumes that your keyboard is QWERTY, here KEY_W means KEY_Z on AZERTY keyboard
        _paddle1.MoveUp();

    if (IsKeyDown(KEY_S))
        _paddle1.MoveDown();
}

void Game::_HandleCollisions()
{
    // === Ball-Border collisions ===
    if(_ball.GetRectangle().y < 0.0f)
        _ball.HandleBounceTop();
    else if(_ball.GetRectangle().y > GetScreenHeight() - _ball.GetRectangle().height) 
        _ball.HandleBounceBottom();

    if(_ball.GetRectangle().x <= 0.0f)
        _isGameOver = true;
    else if(_ball.GetRectangle().x >= GetScreenWidth() - 30.0f - _ball.GetRectangle().width)
        _ball.HandleBounceRight();    // Replace the bot logic


    // === Ball-Paddle1 collisions ===
    if (_ball.GetSpeed().x < 0.0f)     // Here the ball will into the paddle1
    {
        if (CheckCollisionRecs(_ball.GetRectangle(), _paddle1.GetRectangle()))
        {
            _ball.HandleBounceLeft();
            _score++;
        };
    }

    // === Ball-Paddle2 collisions ===                  // Commented because this paddle does not move right now
    // else    // Here the ball will into the paddle2
    // {
    //     if (CheckCollisionRecs(_ball.GetRectangle(), _paddle2.GetRectangle()))
    //     {
    //         _ball.RightBounce();      
    //         _score++;
    //     };
    // };
}

void Game::_Restart()
{
    _ball.Reset();
    _paddle1.Reset(30.0f);
    _paddle2.Reset(GetScreenWidth() - 30.0f);

    _isGameOver = false;
    _score = 0;
}