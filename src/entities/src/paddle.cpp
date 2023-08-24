#include "paddle.hpp"
#include "globals.hpp"


Paddle::Paddle(const float positionX)
    : _size({GetReelValue(10.0f), GetReelValue(100.0f)}),
      _position({positionX, (GAME_HEIGHT / 2.0f) - (_size.y / 2.0f)}),
      _speed(GetReelValue(900.0f))
{}


// === Accessors ===
rl::Vector2 Paddle::GetPosition() const {
    return _position;
}

float Paddle::GetSpeed() const {
    return _speed;
}

rl::Rectangle Paddle::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Mutators ===
void Paddle::SetPosition(const rl::Vector2& newPosition) {
    _position.x = newPosition.x;
    _position.y = newPosition.y;
}

void Paddle::MoveUp() {
    // Vérifie si le paddle atteint le bord supérieur de l'écran
    if (_position.y - _speed * rl::GetFrameTime() > 10.0f) {
        _position.y -= _speed * rl::GetFrameTime();
    } else {
        _position.y = 10.0f;
    }
}

void Paddle::MoveDown() {
    // Vérifie si le paddle atteint le bord inférieur de l'écran
    if (_position.y + _size.y + _speed * rl::GetFrameTime() < WINDOW_HEIGHT - 10.0f) {
        _position.y += _speed * rl::GetFrameTime();
    } else {
        _position.y = WINDOW_HEIGHT - _size.y - 10.0f;
    }
}

void Paddle::SetSpeed(const float newSpeed) {
    _speed = newSpeed;
}

void Paddle::Reset(const float positionX)
{
    _size = {GetReelValue(10.0f), GetReelValue(100.0f)};
    _position = {(positionX), (GAME_HEIGHT / 2.0f) - (_size.y / 2.0f)};
    _speed = GetReelValue(900.0f);
}

// === Rendering ===
void Paddle::Render() const {
    rl::DrawRectangle(MARGIN_X + _position.x, MARGIN_Y + _position.y, _size.x, _size.y, rl::BLACK);
}