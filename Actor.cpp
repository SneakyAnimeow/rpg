#include "Actor.h"

Actor::Actor(float x, float y, float height, float width, sf::Color color)
    : _x(x), _y(y), _height(height), _width(width), _color(color)
{
}

void Actor::move(float newX, float newY)
{
    _x = newX;
    _y = newY;
}

void Actor::resize(float newHeight, float newWidth)
{
    _height = newHeight;
    _width = newWidth;
}

float Actor::getX() const
{
    return _x;
}

float Actor::getY() const
{
    return _y;
}

void Actor::setX(float x)
{
    _x = x;
}

void Actor::setY(float y)
{
    _y = y;
}

bool Actor::isInteractingWith(const Actor& other) const
{
    return _x < other._x + other._width &&
           _x + _width > other._x &&
           _y < other._y + other._height &&
           _y + _height > other._y;
}

sf::Color Actor::getColor() const
{
    return _color;
}

void Actor::setColor(sf::Color color)
{
    _color = color;
}

float Actor::getHeight() const
{
    return _height;
}

float Actor::getWidth() const
{
    return _width;
}

void Actor::setHeight(float height)
{
    _height = height;
}

void Actor::setWidth(float width)
{
    _width = width;
}