#include <SFML/Graphics.hpp>

#include "player.h"

const int WIDTH = 1280;
const int HEIGHT = 1080;

int main()
{
    sf::Color backgroundPurple(125, 38, 205);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    window.setFramerateLimit(120);
    // window.setVerticalSyncEnabled(true);

    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(backgroundPurple);

    sf::Clock clock;

    Player player; 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
        
        sf::Time deltaTime = clock.restart();
        
        player.run(deltaTime);

        window.clear();
        
        window.draw(background);
        player.draw(&window);

        window.display();
    }

    return 0;
}
