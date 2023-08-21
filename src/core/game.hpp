#pragma once
#include "ball.hpp"
#include "paddle.hpp"


class Game
{
public:
    Game();
    void Update();
    void Draw();

private:
    void ManageCollisionBallWall();
    void ManageCollisionBallPaddle();
    void Restart();

    Ball ball;
    Paddle paddle1;
    Paddle paddle2;

    bool running;
    int unsigned score;
};