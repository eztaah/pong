#include "MenuState.hpp"
#include "globals.hpp"


MenuState::MenuState(Game* game)
    : _cursorPosition(0),
      _texturesArray(),
      _game(game)
{}


void MenuState::OnEnter()
{
    _cursorPosition = 0;

    // load textures
    _texturesArray.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_0.png"));
    _texturesArray.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_1.png"));
    _texturesArray.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_2.png"));
    _texturesArray.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_3.png"));
}

void MenuState::OnExit()
{
    // Unload textures
    _texturesArray.clear();
}

void MenuState::Update()
{
    // Move cursor
    if (rl::IsKeyPressed(rl::KEY_UP) || rl::IsKeyPressed(rl::KEY_W))
    {
        if(_cursorPosition == 0)
            _cursorPosition = 3;
        else
            _cursorPosition -= 1;
    }
    if (rl::IsKeyPressed(rl::KEY_DOWN) || rl::IsKeyPressed(rl::KEY_S))
    {
        if(_cursorPosition == 3)
            _cursorPosition = 0;
        else
            _cursorPosition += 1;
    }


    // Start Game
    if (rl::IsKeyPressed(rl::KEY_SPACE) || rl::IsKeyPressed(rl::KEY_ENTER))
    {
        switch(_cursorPosition)
        {
            case 0:
                _game->StartGame();
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

void MenuState::Render()
{
    float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_texturesArray[_cursorPosition].width);
    rl::DrawTextureEx(_texturesArray[_cursorPosition], {0.0f, 0.0f}, 0.0f, scale, rl::WHITE); 
}