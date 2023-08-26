#pragma once
#include <libs.hpp>


class Ball
{
public:
    Ball(const rl::Color& color);

    // === Movmement & Logic ===
    virtual void Update();
    void HandleBounceTop();
    void HandleBounceBottom();
    void HandleBounceLeft();
    void HandleBounceRight();

    // === Accessors ===
    rl::Vector2 GetPosition() const;
    rl::Vector2 GetSpeed() const;
    float GetSize() const;
    rl::Rectangle GetRectangle() const;
    bool IsActive() const;

    // === Mutators ===
    void SetPosition(const rl::Vector2& newPosition);
    void SetSpeed(const rl::Vector2& newSpeed);
    void Reset();
    void Activate();
    void Desactivate();

    // === Rendering ===
    void Render() const;

private:
    bool _isActive;
    float _size;
    rl::Vector2 _position;
    float _speedCoeff;
    rl::Vector2 _speed;
    rl::Color _color;
};
