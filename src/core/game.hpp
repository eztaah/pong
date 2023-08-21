#pragma once
#include "ball.hpp"
#include "paddle.hpp"
#include <vector>
#include <memory>


class Game
{
public:
    Game();
    void Update();
    void Render();

private:
    void _HandleInputs();
    void _HandleCollisions();
    void _Restart();

    Ball _ball;
    Ball _ghostBall;
    Paddle _paddle1;
    Paddle _paddle2;

    float _botDefensePosition;
    std::vector<Ball*> _ballsArray;
    bool _isGameOver;
    int unsigned _score;
};