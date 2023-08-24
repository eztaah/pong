#pragma once
#include "GameState.hpp"
#include "libs.hpp"


class PlayingState : public GameState
{
public:
    PlayingState();

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render() override;

private: 

};