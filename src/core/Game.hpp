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

    unsigned int GetScore() const;
    void IncreaseScore();
    void ResetScore();

private:
    void _ChangeState(std::unique_ptr<GameState> newState);
    std::unique_ptr<GameState> _currentState;
    int unsigned _score;
};