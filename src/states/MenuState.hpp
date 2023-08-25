#pragma once
#include "GameState.hpp"
#include "Game.hpp"
#include "libs.hpp"
#include <memory>
#include <vector>


class MenuState : public GameState
{
public:
    MenuState(Game* game);

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 
    Game* _game;
    int _cursorPosition;
    std::vector<rl::Texture2D> _texturesArray;
};