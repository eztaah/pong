#pragma once
#include "libs.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include <vector>
#include <memory>

#include "GameState.hpp"
#include "MenuState.hpp"
#include "PlayingState.hpp"
#include "GameOverState.hpp"


class Game
{
public:
    Game();
    void Update();
    void Render();
    void Reset();

private:
    void _HandleInputs();
    void _HandleCollisions();
    void _Start();

    Ball _ball;
    Ball _ghostBall;
    Paddle _paddle1;
    Paddle _paddle2;

    float _botDefensePosition;
    std::vector<Ball*> _ballsArray;
    bool _isGameOver;
    int unsigned _score;
    std::unique_ptr<GameState> _currentState;
};