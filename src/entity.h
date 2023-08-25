#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Entity
{
public:
    virtual void run(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif
