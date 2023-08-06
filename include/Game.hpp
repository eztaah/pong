#pragma once

#include <Ball.hpp>
#include <Paddle.hpp>

class Game
{
    public:
        Game();
        void Draw();
        void Update();

    private:
        Ball ball;
        Paddle paddle;
};