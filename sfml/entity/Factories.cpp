//
// Created by mats_ on 11/09/2025.
//

#include "Factories.h"
#include "EntityManager.h"
#include "component/Moviment.h"
#include "component/Shape.h"
#include "utils/Colors.h"

void Factories::createEntityCharacter(EntityManager& em) {

    sf::Color color = ColorsMap.at(GameColor::blue);
    sf::Vector2f velocity(5,5);
    sf::Vector2f position(50,50);
    createEntityShape(em, 8, color, velocity, position, 0, 0);

}

void Factories::createEntityCircle(EntityManager& em) {

    sf::Color color = ColorsMap.at(GameColor::red);
    sf::Vector2f velocity(5,5);
    sf::Vector2f position(5,5);
    createEntityShape(em, 100, color, velocity, position, 1,10);

}

void Factories::createEntityTriangle(EntityManager& em) {

    sf::Color color = ColorsMap.at(GameColor::gray);
    sf::Vector2f velocity(5,5);
    sf::Vector2f position(100,100);
    createEntityShape(em, 4, color, velocity, position, 2, 10);

}

void Factories::createEntityShape(EntityManager& em, int numberOfSides, sf::Color& color, sf::Vector2f& velocity, sf::Vector2f& position, int type, float rotation) {

    Entity character = em.createEntity();
    em.addComponent<Velocity>(character, velocity);
    em.addComponent<Position>(character, position);
    em.addComponent<Sides>(character, numberOfSides);
    em.addComponent<Color>(character, color);
    em.addComponent<Type>(character, type );
    em.addComponent<Visible>(character, true);
    em.addComponent<Rotation>(character, 0.f,rotation);


}