#include "PlayingState.hpp"


PlayingState::PlayingState()
{}


void PlayingState::OnEnter()
{

}

void PlayingState::OnExit()
{

}

void PlayingState::Update()
{
    // Update paddle 1 position
    _HandleInputs();

    // Update paddle 2 position
    if(_paddle2.GetPosition().y + (_paddle2.GetRectangle().height / 2) < _botDefensePosition)
        _paddle2.MoveDown();
    if(_paddle2.GetPosition().y + (_paddle2.GetRectangle().height / 2) > _botDefensePosition)
        _paddle2.MoveUp();

    // Update balls position
    for(Ball* elt : _ballsArray)
        elt->Update();

    _HandleCollisions();
}

void PlayingState:Render()
{
    // === Draw entities ===
    _paddle1.Render();
    _paddle2.Render();
    _ball.Render();
    _ghostBall.Render();

    // === Draw score ===
    std::string scoreStr = std::to_string(_score);   // Convert score to a string
    rl::DrawText(scoreStr.c_str(), GetReelValue(670.0f), GetReelValue(20.0f), GetReelValue(40.0f), rl::BLACK);     // Display the score
}