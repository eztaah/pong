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

    // === Games states ===
    void SetMenuState();
    void SetPlayingState();
    void SetGameOverState();

    // === Score ===
    unsigned int GetScore() const;
    void IncreaseScore();
    void ResetScore();

private:
    void _ChangeState(std::unique_ptr<GameState> newState);
    std::unique_ptr<GameState> _currentState;
    int unsigned _score;
};