#include "globals.hpp"
#include "game.hpp"
#include "window_manager.hpp"
#include <string>
#include <cmath>


///////////////// PUBLIC /////////////////
Game::Game()
    : _ball(BLACK),
      _ghostBall(RED),
      _paddle1(30.0f),
      _paddle2(GAME_WIDTH - 30.0f),
      _ballsArray(),
      _isGameOver(false),
      _score(0)
{
    // Set initial position for ball and ghost ball
    _ball.SetPosition({(GAME_WIDTH / 2.0f) - (_ball.GetSize() / 2.0f), (GAME_HEIGHT / 2.0f) - (_ball.GetSize() / 2.0f)});
    _ghostBall.SetPosition({(GAME_WIDTH / 2.0f) - (_ghostBall.GetSize() / 2.0f), (GAME_HEIGHT / 2.0f) - (_ghostBall.GetSize() / 2.0f)});
 
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
    ClearBackground(BLACK);

    // Set up the drawing area
    BeginScissorMode(MARGIN_X, MARGIN_Y, GAME_WIDTH, GAME_HEIGHT);
    ClearBackground(RAYWHITE);  // Fill the game area with green

    // === Draw entities ===
    _paddle1.Render();
    _paddle2.Render();
    if(!_isGameOver)
        _ball.Render();
    _ghostBall.Render();

    // === Draw score ===
    std::string scoreStr = std::to_string(_score);   // Convert score to a string
    DrawText(scoreStr.c_str(), MARGIN_X + GetReelValue(670.0f), MARGIN_Y + GetReelValue(20.0f), GetReelValue(40.0f), BLACK);     // Display the score

    // === Draw restart message (if game over)===
    if(_isGameOver)
        DrawText("PRESS SPACE TO RESTART", MARGIN_X + (GAME_WIDTH / 2.0f) - GetReelValue(290.0f), MARGIN_Y + (GAME_HEIGHT / 2.0f) - GetReelValue(10.0f), GetReelValue(40.0f), GRAY);

    EndScissorMode();
    EndDrawing();
}

void Game::Reset()
{
    _ball.Reset();
    _ghostBall.Reset();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
    _paddle1.Reset(GetReelValue(30.0f));
    _paddle2.Reset(GAME_WIDTH - GetReelValue(30.0f));

    _isGameOver = false;
    _score = 0;
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
        else if(elt->GetRectangle().y > GAME_HEIGHT - elt->GetRectangle().height) 
            elt->HandleBounceBottom();
    }


    // === Ball-Horizontal-Border collisions ===
    if(_ball.GetRectangle().x <= 0.0f)
        _isGameOver = true;
    else if(_ball.GetRectangle().x >= GAME_WIDTH - 30.0f - _ball.GetRectangle().width)
        _ball.HandleBounceRight();    // Prevent bot from losing


    // === Ball-Paddle1 collisions ===
    if (_ball.GetSpeed().x < 0.0f)     // Here the ball will go into the paddle1
    {
        if (CheckCollisionRecs(_ball.GetRectangle(), _paddle1.GetRectangle()))
        {
            float mismatch{_ball.GetRectangle().y - _paddle1.GetRectangle().y - (_paddle1.GetRectangle().height / 2)};

            _ball.HandleBounceLeft(mismatch);

            _score++;

            // Ghost ball
            _ghostBall.SetPosition(_ball.GetPosition());
            _ghostBall.Activate();
            _ghostBall.SetSpeed({_ball.GetSpeed().x * 10, _ball.GetSpeed().y * 10});
        };
    }


    // === Ghost-ball right wall collision
    if(_ghostBall.GetPosition().x >= GAME_WIDTH - _ghostBall.GetSize() - 30.0f)
    {
        _ghostBall.Desactivate();
        _botDefensePosition = _ghostBall.GetPosition().y + (_ghostBall.GetSize() / 2);
    }
}

void Game::_Restart()
{
    _ball.Reset();
    _ghostBall.Reset();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
    _paddle1.Reset(30.0f);
    _paddle2.Reset(GAME_WIDTH - 30.0f);

    _isGameOver = false;
    _score = 0;
}