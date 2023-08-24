#pragma once
#include "ball.hpp"
#include "paddle.hpp"
#include "libs.hpp"
#include <vector>


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

    // === Update ===
    void _UpdateStartMenu();
    void _UpdateGame();
    void _UpdateEndMenu();

    // === Render ===
    void _RenderStartMenu();
    void _RenderGame();
    void _RenderEndMenu();

    Ball _ball;
    Ball _ghostBall;
    Paddle _paddle1;
    Paddle _paddle2;

    float _botDefensePosition;
    std::vector<Ball*> _ballsArray;
    bool _isGameOver;
    int unsigned _score;
    int _state;
    int _cursorPosition;

    std::vector<rl::Texture2D> _texturesArray;
};