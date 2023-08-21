#include "paddle.hpp"
#include "globals.hpp"
#include <raylib.hpp>


Paddle::Paddle(const float positionX)
    : _size({GetReelValue(10.0f), GetReelValue(100.0f)}),
      _position({MARGIN_X + positionX, MARGIN_Y + (GAME_HEIGHT / 2.0f) - (_size.y / 2.0f)}),
      _speed(GetReelValue(900.0f))
{}


// === Accessors ===
Vector2 Paddle::GetPosition() const {
    return _position;
}

float Paddle::GetSpeed() const {
    return _speed;
}

Rectangle Paddle::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Mutators ===
void Paddle::SetPosition(const Vector2& newPosition) {
    _position.x = MARGIN_X + newPosition.x;
    _position.y = MARGIN_Y + newPosition.y;
}

void Paddle::MoveUp() {
    _position.y -= _speed * GetFrameTime();
}

void Paddle::MoveDown() {
    _position.y += _speed * GetFrameTime();
}

void Paddle::SetSpeed(const float newSpeed) {
    _speed = newSpeed;
}

void Paddle::Reset(const float positionX)
{
    _size = {GetReelValue(10.0f), GetReelValue(100.0f)};
    _position = {MARGIN_X + (positionX), MARGIN_Y + (GAME_HEIGHT / 2.0f) - (_size.y / 2.0f)};
    _speed = GetReelValue(900.0f);
}


// === Rendering ===
void Paddle::Render() const {
    DrawRectangle(_position.x, _position.y, _size.x, _size.y, BLACK);
}