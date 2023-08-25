#pragma once
#include "GameState.hpp"
#include "libs.hpp"
#include "Game.hpp"


class GameOverState : public GameState
{
public:
    GameOverState(Game* game);

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 
    Game* _game;
    rl::Texture2D _texture;
};