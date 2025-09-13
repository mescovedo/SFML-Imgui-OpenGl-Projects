//
// Created by mats_ on 11/09/2025.
//

#pragma once

#include <optional>
#include "Entity.h"
#include "EntityManager.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"

namespace Factories {

    void createEntityCharacter(EntityManager& em);
    void createEntityShape(EntityManager& em, int numberOfSides, sf::Color& color, sf::Vector2f& velocity, sf::Vector2f& position, int type, float rotation);
    void createEntityCircle(EntityManager& em);
    void createEntityTriangle(EntityManager& em);

};



