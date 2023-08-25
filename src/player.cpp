#include <SFML/Graphics.hpp>

#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <math.h>
#include <ostream>
#include "player.h"

Player::Player()
{
    sf::CircleShape shape(40.f, 3);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(40.f, 40.f);
    shape.setPosition(640.f, 540.f);

    this->shape = shape;

}

void Player::run(sf::Time deltaTime)
{
    for(Shot shot: shots)
    {
        std::cout << "Processing shots\n";
        shot.run(deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        auto radians = ((3.1415926536 / 180) * shape.getRotation());

        float x = sin(radians) * velocity;
        float y = -cos(radians) * velocity;
        
        shape.move(x, y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
       shots.push_back(Shot()); 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        shape.rotate(-2.5f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        shape.rotate(2.5f);
    }

}

void Player::draw(sf::RenderWindow *window)
{
    window->draw(shape);

    for(Shot shot: shots)
    {
        shot.draw(window);
    }
}

Shot::Shot()
{
    sf::CircleShape shotShape(5.f, 3);
    shotShape.setFillColor(sf::Color::White);
    shotShape.setOrigin(5.f, 5.f);
    shotShape.setPosition(640.f, 540.f);
    this->shotShape = shotShape;
}

void Shot::run(sf::Time deltaTime)
{
    shotShape.move(1.f, 1.f);
}

void Shot::draw(sf::RenderWindow *window)
{
    window->draw(shotShape);
}
