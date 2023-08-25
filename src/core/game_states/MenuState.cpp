#include "MenuState.hpp"
#include "globals.hpp"


MenuState::MenuState(Game* game)
    : _game(game),
      _cursorPosition(0),
      _state(0),
      _mainMenuTextures(),
      _settingsTextures()
{}


void MenuState::OnEnter()
{
    _cursorPosition = 0;

    // === Load textures ===
    // Main menu textures
    _mainMenuTextures.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_0.png"));
    _mainMenuTextures.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_1.png"));
    _mainMenuTextures.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_2.png"));
    _mainMenuTextures.push_back(rl::LoadTexture("../assets/textures/daymode/main_menu_3.png"));
    _mainMenuTextures.push_back(rl::LoadTexture("../assets/textures/daymode/2_players_mode_coming_soon.png"));
    // Settings textures
    _settingsTextures.push_back(rl::LoadTexture("../assets/textures/daymode/setting_menu_0.png"));
    _settingsTextures.push_back(rl::LoadTexture("../assets/textures/daymode/setting_menu_1.png"));
    _settingsTextures.push_back(rl::LoadTexture("../assets/textures/daymode/setting_menu_2.png"));
    _settingsTextures.push_back(rl::LoadTexture("../assets/textures/daymode/setting_menu_3.png"));
}

void MenuState::OnExit()
{
    // Unload textures
    _mainMenuTextures.clear();
    _settingsTextures.clear();
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

    // If key pressed
    if (rl::IsKeyPressed(rl::KEY_SPACE) || rl::IsKeyPressed(rl::KEY_ENTER))
    {
        if(_state == 0)
            _ManageKeyPressedMainMenu();
        else if(_state == 1)
            _ManageKeyPressedSettings();
        else
            _state = 0;
    }
}

void MenuState::Render()
{
    if(_state == 0)
    {
        float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_mainMenuTextures[_cursorPosition].width);
        rl::DrawTextureEx(_mainMenuTextures[_cursorPosition], {0.0f, 0.0f}, 0.0f, scale, rl::WHITE); 
    } else if(_state == 1) 
    {
        float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_settingsTextures[_cursorPosition].width);
        rl::DrawTextureEx(_settingsTextures[_cursorPosition], {0.0f, 0.0f}, 0.0f, scale, rl::WHITE); 
    } else if(_state == -1)
    {
        float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_mainMenuTextures[4].width);
        rl::DrawTextureEx(_mainMenuTextures[4], {0.0f, 0.0f}, 0.0f, scale, rl::WHITE);  
    }
}


////////////////////// PRIVATE /////////////////////////
void MenuState::_ManageKeyPressedMainMenu()
{
    switch(_cursorPosition)
    {
        case 0:
            _game->SetPlayingState();
            break;
        case 1:
            _state = -1;
            break;
        case 2:
            _state = 1;
            break;
        case 3:
            rl::CloseWindow();
            break;
    }
}

void MenuState::_ManageKeyPressedSettings()
{
    switch(_cursorPosition)
    {
        case 0:
            _game->ToggleFullScreenWindow();
            break;
        case 1:
            _game->ToggleMusic();
            break;
        case 2:
            // Night mode
            break;
        case 3:
            _state = 0;
            break;
    }
}