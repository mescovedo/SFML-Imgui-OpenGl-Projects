#include "InputSystem.h"
#include "component/Moviment.h"
#include "SFML/Window/Keyboard.hpp"
#include "component/Shape.h"

void InputSystem::update(EntityManager &em, sf::RenderWindow &window) {
    auto entities = em.getEntities();

    for (auto e: entities){
        if (em.getComponent<Type>(e)->value == 0) {
            auto input = em.getComponent<InputState>(e);


            input->up    = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            input->down  = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            input->left  = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            input->right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

        }
    }
}