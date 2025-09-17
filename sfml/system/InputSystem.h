

#pragma once

#include "entity/EntityManager.h"
#include "SFML/Graphics/RenderWindow.hpp"

class InputSystem {
public:
    void update(EntityManager &em, sf::RenderWindow& window);

};

