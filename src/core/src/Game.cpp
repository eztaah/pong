#include "globals.hpp"
#include "Game.hpp"
#include "WindowManager.hpp"
#include <string>
#include <cmath>


///////////////// PUBLIC /////////////////
Game::Game()
    : _ball(rl::BLACK),
      _ghostBall(rl::RED),
      _paddle1(30.0f),
      _paddle2(GAME_WIDTH - 30.0f),
      _ballsArray(),
      _score(0),
      _currentState(std::make_unique<MenuState>())
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
    _currentState->Update();
}

void Game::Render()
{
    rl::BeginDrawing();
    rl::ClearBackground(rl::BLACK);

    // Set up the drawing area
    rl::BeginScissorMode(MARGIN_X, MARGIN_Y, GAME_WIDTH, GAME_HEIGHT);
    rl::ClearBackground(rl::RAYWHITE);  // Fill the game area with green

    _currentState->Render();

    rl::EndScissorMode();
    rl::EndDrawing();
}

void Game::Reset()
{
    _ball.Reset();
    _ghostBall.Reset();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
    _paddle1.Reset(GetReelValue(30.0f));
    _paddle2.Reset(GAME_WIDTH - GetReelValue(30.0f));
    _score = 0;
    //_state = 0;
}


///////////////// PRIVATE /////////////////
void Game::_HandleInputs()
{
    if (rl::IsKeyDown(rl::KEY_W) || rl::IsKeyDown(rl::KEY_UP))   // Raylib assumes that your keyboard is QWERTY, here KEY_W means KEY_Z on AZERTY keyboard
        _paddle1.MoveUp();

    if (rl::IsKeyDown(rl::KEY_S) || rl::IsKeyDown(rl::KEY_DOWN))
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
    {
        //_state = 0;     // Game Over
    }
    else if(_ball.GetRectangle().x >= GAME_WIDTH - 30.0f - _ball.GetRectangle().width)
        _ball.HandleBounceRight();    // Prevent bot from losing


    // === Ball-Paddle1 collisions ===
    if (_ball.GetSpeed().x < 0.0f)     // Here the ball will go into the paddle1
    {
        if (rl::CheckCollisionRecs(_ball.GetRectangle(), _paddle1.GetRectangle()))
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

void Game::_Start()
{
    _ball.Reset();
    _ghostBall.Reset();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
    _paddle1.Reset(30.0f);
    _paddle2.Reset(GAME_WIDTH - 30.0f);
    _score = 0;
    //_state = 1;
}


