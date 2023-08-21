#pragma once
#include <raylib.hpp>


class Ball
{
public:
    Ball();

    // === Movmement & Logic ===
    void Update();
    void HandleBounceTop();
    void HandleBounceBottom();
    void HandleBounceLeft();
    void HandleBounceRight();

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetSpeed() const;
    Rectangle GetRectangle() const;

    // === Mutators ===
    void SetPosition(const Vector2& newPosition);
    void SetSpeed(const Vector2& newSpeed);
    void Reset();

    // === Rendering ===
    void Render() const;

private:
    float _size;
    Vector2 _position;
    Vector2 _speed;
};