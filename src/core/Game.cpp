#include "globals.hpp"
#include "Game.hpp"
#include "Window_manager.hpp"
#include <string>
#include <cmath>


///////////////// PUBLIC /////////////////
Game::Game()
    : _ball(BLACK),
      _ghostBall(RED),
      _paddle1(30.0f),
      _paddle2(GAME_WIDTH - 30.0f),
      _ballsArray(),
      _score(0),
      _state(0),
      _cursorPosition(0),
      _texturesArray()
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

    // load texture
    _texturesArray.push_back(LoadTexture("../assets/textures/daymode/main_menu_0.png"));
    _texturesArray.push_back(LoadTexture("../assets/textures/daymode/main_menu_1.png"));
    _texturesArray.push_back(LoadTexture("../assets/textures/daymode/main_menu_2.png"));
    _texturesArray.push_back(LoadTexture("../assets/textures/daymode/main_menu_3.png"));

}

void Game::Update()
{
    switch(_state)
    {
        case 0:
            _UpdateStartMenu();
            break;
        
        case 1:
            _UpdateGame();
            break;
        case 2:
            _UpdateEndMenu();
            break;
    }
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Set up the drawing area
    BeginScissorMode(MARGIN_X, MARGIN_Y, GAME_WIDTH, GAME_HEIGHT);
    ClearBackground(RAYWHITE);  // Fill the game area with green

    switch(_state) 
    {
        case 0:
            _RenderStartMenu();
            break;
        
        case 1:
            _RenderGame();
            break;
        case 2:
            _RenderEndMenu();
            break;
    }

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
        _state = 0;     // Game Over
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

void Game::_Start()
{
    _ball.Reset();
    _ghostBall.Reset();
    _ghostBall.Activate();
    _ghostBall.SetSpeed({_ball.GetSpeed().x * 10.0f, _ball.GetSpeed().y * 10.0f});
    _paddle1.Reset(30.0f);
    _paddle2.Reset(GAME_WIDTH - 30.0f);
    _score = 0;
    _state = 1;
}


void Game::_UpdateStartMenu()
{
    // Move cursor
    if (IsKeyPressed(KEY_UP))
    {
        if(_cursorPosition == 0)
            _cursorPosition = 3;
        else
            _cursorPosition -= 1;
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        if(_cursorPosition == 3)
            _cursorPosition = 0;
        else
            _cursorPosition += 1;
    }

    // Start Game
    if (IsKeyDown(KEY_SPACE))
    {
        switch(_cursorPosition)
        {
            case 0:
                _Start();   // <- mettre game state = 2
                break;
            case 1:
                // 2 Players    // game state = 3
                break;
            case 2:
                // Settings
                break;
            case 3:
                // Exit
                break;
        }
    }
}


void Game::_UpdateGame()
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

void Game::_UpdateEndMenu()
{
    if (IsKeyDown(KEY_SPACE))
        _Start();
}


// === Render ===
void Game::_RenderStartMenu()
{
    float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_texturesArray[_cursorPosition].width);
    DrawTextureEx(_texturesArray[_cursorPosition], {MARGIN_X + 0.0f, MARGIN_Y + 0.0f}, 0.0f, scale, WHITE); 
}

void Game::_RenderGame()
{
    // === Draw entities ===
    _paddle1.Render();
    _paddle2.Render();
    _ball.Render();
    _ghostBall.Render();

    // === Draw score ===
    std::string scoreStr = std::to_string(_score);   // Convert score to a string
    DrawText(scoreStr.c_str(), MARGIN_X + GetReelValue(670.0f), MARGIN_Y + GetReelValue(20.0f), GetReelValue(40.0f), BLACK);     // Display the score
}

void Game::_RenderEndMenu()
{
    DrawText("PRESS SPACE TO RESTART", MARGIN_X + (GAME_WIDTH / 2.0f) - GetReelValue(290.0f), MARGIN_Y + (GAME_HEIGHT / 2.0f) - GetReelValue(10.0f), GetReelValue(40.0f), GRAY); 
}
