//
// Created by mats_ on 12/09/2025.
//

#pragma once

#include "entity/EntityManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SpawnSystem.h"
#include "CollisionSystem.h"

class RenderSystem {

private:
    void removeInvisible(EntityManager &em);
public:
    void update(EntityManager& em, sf::RenderWindow& window);

};