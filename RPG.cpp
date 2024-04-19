#include <any>
#include <SFML/Graphics.hpp>

#include "Actor.h"
#include "PlayerActor.h"

std::vector<Actor> actors = {
    Actor(0, 0, 20, 20, sf::Color::Green),
    Actor(200, 200, 20, 20, sf::Color::Blue),
    Actor(400, 400, 20, 20, sf::Color::Red)
};

PlayerActor player(100, 100, 40, 40, 1, sf::Color::Yellow);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Handle arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(Direction::UP);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(Direction::DOWN);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(Direction::LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(Direction::RIGHT);

        // Clear screen
        window.clear();

        // Draw the actors
        for (const auto& actor : actors)
        {
            sf::RectangleShape square(sf::Vector2f(actor.getWidth(), actor.getHeight()));
            square.setFillColor(actor.getColor());
            square.setPosition(actor.getX(), actor.getY());

            window.draw(square);
        }

        sf::RectangleShape square(sf::Vector2f(player.getWidth(), player.getHeight()));
        square.setFillColor(player.getColor());
        square.setPosition(player.getX(), player.getY());

        window.draw(square);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}