#pragma once

#include <Ball.hpp>
#include <Paddle.hpp>

class Game
{
    public:
        Game();
        void Draw();
        void Update();
        
        void ManageCollisionBallWall();

    private:
        Ball ball;
        Paddle paddle;
};