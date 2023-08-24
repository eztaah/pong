#pragma once
#include "GameState.hpp"
#include "libs.hpp"
#include <vector>


class MenuState : public GameState
{
public:
    MenuState();

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 
    int _cursorPosition;
    std::vector<rl::Texture2D> _texturesArray;
};