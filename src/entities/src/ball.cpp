#include "ball.hpp"
#include <raylib.hpp>
#include <string>


Ball::Ball(const Color& color)
    : _isActive(false),
      _size(14.0f),
      _position({0.0f, 0.0f}),
      _speed({300.0f, 200.0f}),
      _color(color)
{}


// === Movmement & Logic ===
void Ball::Update()
{
    if(_isActive)
    {
        _position.x += _speed.x * GetFrameTime();   // * GetFrameTime() permet de rendre le déplacement de la balle constant
        _position.y += _speed.y * GetFrameTime();
    }
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

float Ball::GetSize() const {
    return _size;
}

Rectangle Ball::GetRectangle() const {
    return {_position.x, _position.y, _size, _size};
}

bool Ball::IsActive() const {
    return _isActive;
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

void Ball::Activate() {
    _isActive = true;
}

void Ball::Desactivate() {
    _isActive = false;
}


// === Rendering ===
void Ball::Render() const {
    DrawRectangle(_position.x, _position.y, _size, _size, _color);
}