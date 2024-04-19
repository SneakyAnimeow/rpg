#pragma once
#include "Actor.h"
#include "Direction.cpp"

class PlayerActor : public Actor
{
private:
    float _speed;
public:
    float getSpeed() const;
    void setSpeed(float speed);
    void move(Direction direction);
    PlayerActor(float x, float y, float height, float width, float speed, sf::Color color);
};
