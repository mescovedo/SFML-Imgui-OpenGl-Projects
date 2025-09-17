
#include "entity/EntityManager.h"
#include "SFML/System/Vector2.hpp"

class MovementSystem {
public:
    void update(EntityManager &em, float dt,  sf::Vector2u winSize);
};
