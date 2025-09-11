//
// Created by mats_ on 11/09/2025.
//

#include "Factories.h"
#include "EntityManager.h"
#include "component/Moviment.h"

Entity* Factories::createEntityCharacter(EntityManager em) {

    Entity character = em.createEntity();
    em.addComponent<Velocity>(character, sf::Vector2f(5,5));
    em.addComponent<Position>(character, sf::Vector2f(0,0));

};

Entity* Factories::createEntityCircle(EntityManager em) {

} ;

Entity* Factories::createEntityShape(const EntityManager em) {

};

Entity* Factories::createEntityTriangle(const EntityManager em) {


};