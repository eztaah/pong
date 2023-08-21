#pragma once
#include "ball.hpp"
#include "paddle.hpp"


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
    Paddle _paddle1;
    Paddle _paddle2;

    bool _isGameOver;
    int unsigned _score;
};