#include "game.hpp"
#include <string>


///////////////// PUBLIC /////////////////
Game::Game()
    : _ball(BLACK),
      _ghostBall(RED),
      _paddle1(30.0f),
      _paddle2(GetScreenWidth() - 30.0f),
      _ballsArray(),
      _isGameOver(false),
      _score(0)
{
    // Set initial position for ball and ghost ball
    _ball.SetPosition({(GetScreenWidth() / 2.0f) - (_ball.GetSize() / 2.0f), (GetScreenHeight() / 2.0f) - (_ball.GetSize() / 2.0f)});
    _ghostBall.SetPosition({(GetScreenWidth() / 2.0f) - (_ghostBall.GetSize() / 2.0f), (GetScreenHeight() / 2.0f) - (_ghostBall.GetSize() / 2.0f)});

    // Setup the array
    _ballsArray.push_back(&_ball);
    _ballsArray.push_back(&_ghostBall);

    // Activate the ball
    _ball.Activate();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
}

void Game::Update()
{
    if(!_isGameOver)
    {
        // Update paddle 1 position
        _HandleInputs();

        // Update paddle 2 position
        if(_paddle2.GetPosition().y + (_paddle2.GetRectangle().height / 2) < _botDefensePosition)
            _paddle2.MoveDown();
        if(_paddle2.GetPosition().y + (_paddle2.GetRectangle().height / 2) > _botDefensePosition)
            _paddle2.MoveUp();

        // Update balls position
        for(Ball* elt : _ballsArray)
            elt->Update();

        _HandleCollisions();
    } 
    else
    {
        if (IsKeyDown(KEY_SPACE))
            _Restart();
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
    _ghostBall.Render();

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
    // === Balls-Vertical-Border collisions ===
    for(Ball* elt : _ballsArray)
    {
        if(elt->GetRectangle().y < 0.0f)
            elt->HandleBounceTop();
        else if(elt->GetRectangle().y > GetScreenHeight() - elt->GetRectangle().height) 
            elt->HandleBounceBottom();
    }

    // === Ball-Horizontal-Border collisions ===
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

            // Ghost ball
            _ghostBall.SetPosition(_ball.GetPosition());
            _ghostBall.Activate();
            _ghostBall.SetSpeed({_ball.GetSpeed().x * 10, _ball.GetSpeed().y * 10});
        };
    }

    // === Ghost-ball right wall collision
    if(_ghostBall.GetPosition().x >= GetScreenWidth() - _ghostBall.GetSize() - 30.0f)
    {
        _ghostBall.Desactivate();
        _botDefensePosition = _ghostBall.GetPosition().y + (_ghostBall.GetSize() / 2);
    }
}

void Game::_Restart()
{
    _ball.Reset();
    _ghostBall.Reset();
    _paddle1.Reset(30.0f);
    _paddle2.Reset(GetScreenWidth() - 30.0f);

    _isGameOver = false;
    _score = 0;
}