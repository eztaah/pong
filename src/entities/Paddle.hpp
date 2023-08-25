#pragma once
#include <libs.hpp>


class Paddle
{
public:
    Paddle(const float positionX);

    // === Accessors ===
    rl::Vector2 GetPosition() const;
    float GetSpeed() const;
    rl::Rectangle GetRectangle() const ;

    // === Movement & Logic ===
    void Update();

    // === Mutators ===
    void SetPosition(const rl::Vector2& newPosition);
    void MoveUp();
    void MoveDown();
    void SetSpeed(const float newSpeed);
    void Reset(const float positionX);

    // === Rendering ===
    void Render() const;

protected:
    rl::Vector2 _size;
    rl::Vector2 _position;
    float _speed;
};
