#pragma once
#include "GameState.hpp"
#include "libs.hpp"


class GameOverState : public GameState
{
public:
    GameOverState();

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 

};