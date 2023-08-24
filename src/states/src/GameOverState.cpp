#include "GameOverState.hpp"


GameOverState::GameOverState()
{}


void GameOverState::OnEnter()
{
    rl::Texture2D texture = rl::LoadTexture("../assets/textures/daymode/game_over.png");
}

void GameOverState::OnExit()
{

}

void GameOverState::Update()
{
    if (rl::IsKeyDown(rl::KEY_SPACE))
        //_Start();
}

void GameOverState:Render()
{

}