

#include "entity/Entity.h"
#include "SFML/System/Vector2.hpp"
#include "entity/EntityManager.h"

#pragma once

class CollisionSystem {

    bool checkCollision(sf::Vector2f pos1, sf::Vector2f pos2,  float angle1, float angle2);

public:
    bool collision(EntityManager &em);
};


