#pragma once
#include "libs.hpp"
#include <vector>
#include <memory>

#include "GameState.hpp"


class Game
{
public:
    Game();
    void Update();
    void Render();
    void Reset();

    void MenuGame();
    void StartGame();
    void EndGame();

private:
    void _ChangeState(std::unique_ptr<GameState> newState);

    std::unique_ptr<GameState> _currentState;
};