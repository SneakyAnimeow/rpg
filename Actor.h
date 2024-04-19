#pragma once
#include <SFML/Graphics/Color.hpp>

class Actor
{
private:
    float _x;
    float _y;
    float _height;
    float _width;
    sf::Color _color;
    
public:
    Actor(float x, float y, float height, float width, sf::Color color = sf::Color::White);
    void move(float newX, float newY);
    void resize(float newHeight, float newWidth);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    bool isInteractingWith(const Actor& other) const;
    sf::Color getColor() const;
    void setColor(sf::Color color);
    float getHeight() const;
    float getWidth() const;
    void setHeight(float height);
    void setWidth(float width);
};
