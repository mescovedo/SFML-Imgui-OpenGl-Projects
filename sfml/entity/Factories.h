#pragma once
#include "EntityManager.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"

namespace Factories {

    void createEntityCharacter(EntityManager& em, sf::Vector2u& winSize);
    void createEntityShape(EntityManager& em, int numberOfSides, sf::Color& color, sf::Vector2f& velocity, sf::Vector2f& position, int type, float rotation, int radius);
    void createEntityCircle(EntityManager& em, sf::Vector2u& winSize);
    void createEntityTriangle(EntityManager& em, sf::Vector2u& winSize );
    void createEntitySquare(EntityManager& em, sf::Vector2u& winSize );
    sf::Vector2f getRandomSpawnPosition(sf::Vector2u& winSize);

};



