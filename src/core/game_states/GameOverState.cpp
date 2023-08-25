#include "GameOverState.hpp"
#include "globals.hpp"


GameOverState::GameOverState(Game* game)
    : _game(game),
     _texture()
{}


void GameOverState::OnEnter()
{
    _texture = rl::LoadTexture("../assets/textures/daymode/game_over.png");
}

void GameOverState::OnExit()
{

}

void GameOverState::Update()
{
    if (rl::IsKeyPressed(rl::KEY_SPACE) || rl::IsKeyPressed(rl::KEY_ENTER))
        _game->SetMenuState();
}

void GameOverState::Render()
{
    // Draw image
    float scale = static_cast<float>(GAME_WIDTH) / static_cast<float>(_texture.width);
    rl::DrawTextureEx(_texture, {0.0f, 0.0f}, 0.0f, scale, rl::WHITE); 

    // Draw score
    std::string scoreStr = std::to_string(_game->GetScore());   // Convert score to a string
    rl::DrawText(scoreStr.c_str(), (GAME_WIDTH / 2) + GetReelValue(-10.0f), GetReelValue(430.0f), GetReelValue(50.0f), rl::BLACK);     // Display the score
}