#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

class Shot: Entity
{
public:
    Shot();
    void run(sf::Time deltaTime) override;
    void draw(sf::RenderWindow *window) override;

private:
    sf::CircleShape shotShape;
    float velocity = 10.f;
};

class Player: public Entity
{
public:
    Player();
    void run(sf::Time deltaTime) override;
    void draw(sf::RenderWindow *window) override;

private:
    std::vector<Shot> shots;
    sf::CircleShape shape;
    float velocity = 5.f;
};



#endif
