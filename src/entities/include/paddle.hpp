#pragma once
#include <raylib.hpp>


class Paddle
{
public:
    Paddle(const float positionX);

    // === Accessors ===
    Vector2 GetPosition() const;
    float GetSpeed() const;
    Rectangle GetRectangle() const ;

    // === Mutators ===
    void SetPosition(const Vector2& newPosition);
    void MoveUp();
    void MoveDown();
    void SetSpeed(const float newSpeed);
    void Reset(const float positionX);


    // === Rendering ===
    void Render() const;

private:
    Vector2 _size;
    Vector2 _position;
    float _speed;
};