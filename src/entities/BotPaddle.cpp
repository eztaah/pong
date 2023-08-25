#include "BotPaddle.hpp"


BotPaddle::BotPaddle(const float positionX)
    : Paddle(positionX)
{}


void BotPaddle::Update(const float botDefensePosition)
{
    // Update paddle 2 position
    if(_position.y + (_size.y / 2) < botDefensePosition)
        MoveDown();
    if(_position.y + (_size.y / 2) > botDefensePosition)
        MoveUp();
}