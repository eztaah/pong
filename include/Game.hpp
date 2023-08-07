#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"

class Game
{
    public:
        Game();
        void ManageCollisionBallWall();
        void ManageCollisionBallPaddle();
        void Update();
        void Draw();
        bool gameOver = false;

    private:
        bool running;
        Ball ball;
        Paddle paddle;
        double coeff = 0.1;
};