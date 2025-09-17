//
// Created by mats_ on 12/09/2025.
//

#pragma once

#include "entity/EntityManager.h"
#include "SFML/System/Vector2.hpp"

class SpawnSystem {

private:

    int timer;
    int spawn_limit;

public:

    void spawn(EntityManager &em, sf::Vector2u& winSize);
    void startTimer();

};
