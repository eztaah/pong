#pragma once
#include "GameState.hpp"
#include "libs.hpp"
#include <memory>
#include <vector>
#include "Game.hpp"


class MenuState : public GameState
{
public:
    MenuState(Game* game);

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 
    int _cursorPosition;
    std::vector<rl::Texture2D> _texturesArray;
    Game* _game;
};