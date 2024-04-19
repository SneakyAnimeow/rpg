#include "PlayerActor.h"

PlayerActor::PlayerActor(float x, float y, float height, float width, float speed, sf::Color color)
    : Actor(x, y, height, width, color), _speed(speed)
{
}

float PlayerActor::getSpeed() const
{
    return _speed;
}

void PlayerActor::setSpeed(float speed)
{
    _speed = speed;
}

void PlayerActor::move(Direction direction)
{
    switch (direction)
    {
    case Direction::UP:
        Actor::move(Actor::getX(), Actor::getY() - _speed);
        break;
    case Direction::DOWN:
        Actor::move(Actor::getX(), Actor::getY() + _speed);
        break;
    case Direction::LEFT:
        Actor::move(Actor::getX() - _speed, Actor::getY());
        break;
    case Direction::RIGHT:
        Actor::move(Actor::getX() + _speed, Actor::getY());
        break;
    }
}