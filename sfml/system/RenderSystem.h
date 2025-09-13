//
// Created by mats_ on 12/09/2025.
//

#pragma once

#include "entity/EntityManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SpawnSystem.h"

class RenderSystem {

public:
    void update(EntityManager& em, sf::RenderWindow& window, SpawnSystem &spawnSystem);

    void setPosition(sf::Vector2f& position, sf::Vector2f& velocity, sf::Vector2u& winSize, bool visible, int tag, int radius, float &angle , float &rotation);
};