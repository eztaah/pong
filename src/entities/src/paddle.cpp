#include "paddle.hpp"
#include <raylib.hpp>


Paddle::Paddle(const float positionX)
    : _size({10.0f, 100.0f}),
      _position({positionX, (GetScreenHeight() / 2.0f) - (_size.y / 2.0f)}),
      _speed(900.0f)
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
    _position = newPosition;
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
    _position = {positionX, (GetScreenHeight() / 2.0f) - (_size.y / 2.0f)};
    _speed = 900.0f;
}


// === Rendering ===
void Paddle::Render() const {
    DrawRectangle(_position.x, _position.y, _size.x, _size.y, BLACK);
}