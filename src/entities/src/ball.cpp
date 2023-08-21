#include "ball.hpp"
#include <raylib.hpp>
#include <string>


Ball::Ball()
    : _size(14.0f),
      _position({(GetScreenWidth() / 2.0f) - (_size / 2.0f), (GetScreenHeight() / 2.0f) - (_size / 2.0f)}),
      _speed({300.0f, 200.0f})
{}


// === Movmement & Logic ===
void Ball::Update()
{
    _position.x += _speed.x * GetFrameTime();   // * GetFrameTime() permet de rendre le déplacement de la balle constant
    _position.y += _speed.y * GetFrameTime();
}

void Ball::HandleBounceTop()
{
    _position.y = 0.0f;    // Prevent bug when the ball go outside the screen
    _speed.y *= -1;
}

void Ball::HandleBounceBottom()
{
    _position.y = GetScreenHeight() - _size;
    _speed.y *= -1;
}

void Ball::HandleBounceLeft()
{
    _position.x = 30.0f;
    _speed.x *= -1;     // bounce

    _speed.x += 100.0f;     // increase speed
    _speed.y += 66.6f;
}

void Ball::HandleBounceRight()
{
    _position.x = GetScreenWidth() - 30.0f - _size;
    _speed.x *= -1;     // bounce
}


// === Accessors ===
Vector2 Ball::GetPosition() const {
    return _position;
}

Vector2 Ball::GetSpeed() const {
    return _speed;
}

Rectangle Ball::GetRectangle() const {
    return {_position.x, _position.y, _size, _size};
}


// === Mutators ===
void Ball::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void Ball::SetSpeed(const Vector2& newSpeed) {
    _speed = newSpeed;
}

void Ball::Reset()
{
    _position = {(GetScreenWidth()/2.0f) - (_size/2), (GetScreenHeight()/2.0f) - (_size/2)};
    _speed = {300.0f, 200.0f};
}


// === Rendering ===
void Ball::Render() const {
    DrawRectangle(_position.x, _position.y, _size, _size, BLACK);
}