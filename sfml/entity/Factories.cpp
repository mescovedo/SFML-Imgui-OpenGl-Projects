
#include "Factories.h"
#include "EntityManager.h"
#include "component/Moviment.h"
#include "component/Shape.h"
#include "utils/Colors.h"
#include "utils/Random.h"
#include "utils/Velocity.h"
#include "utils/Shapes.h"

void Factories::createEntityCharacter(EntityManager& em, sf::Vector2u& winSize) {

    sf::Color color = ColorsMap.at(GameColor::blue);
    sf::Vector2f velocity = VelocityMap.at(GameVelocity::regular);
    sf::Vector2f position = getRandomSpawnPosition(winSize);
    ShapeProperties shapeProperties = MapShapes.at(TypeEntities::character);
    createEntityShape(em, shapeProperties.sides, color, velocity, position, shapeProperties.type, shapeProperties.rotation, shapeProperties.radius);

}

void Factories::createEntityCircle(EntityManager& em, sf::Vector2u& winSize) {

    sf::Color color = ColorsMap.at(GameColor::red);
    sf::Vector2f velocity = VelocityMap.at(GameVelocity::slow);
    sf::Vector2f position = getRandomSpawnPosition(winSize);
    ShapeProperties shapeProperties = MapShapes.at(TypeEntities::circle);
    createEntityShape(em, shapeProperties.sides, color, velocity, position, shapeProperties.type, shapeProperties.rotation, shapeProperties.radius);

}

void Factories::createEntityTriangle(EntityManager& em, sf::Vector2u& winSize) {

    sf::Color color = ColorsMap.at(GameColor::gray);
    sf::Vector2f velocity = VelocityMap.at(GameVelocity::slow);
    sf::Vector2f position = getRandomSpawnPosition(winSize);
    ShapeProperties shapeProperties = MapShapes.at(TypeEntities::triangle);
    createEntityShape(em, shapeProperties.sides, color, velocity, position, shapeProperties.type, shapeProperties.rotation, shapeProperties.radius);

}

void Factories::createEntitySquare(EntityManager& em, sf::Vector2u& winSize) {

    sf::Color color = ColorsMap.at(GameColor::yellow);
    sf::Vector2f velocity = VelocityMap.at(GameVelocity::slow);
    sf::Vector2f position = getRandomSpawnPosition(winSize);
    ShapeProperties shapeProperties = MapShapes.at(TypeEntities::square);
    createEntityShape(em, shapeProperties.sides, color, velocity, position, shapeProperties.type, shapeProperties.rotation, shapeProperties.radius);

}

void Factories::createEntityShape(EntityManager& em, int numberOfSides, sf::Color& color, sf::Vector2f& velocity, sf::Vector2f& position, int type, float rotation, int radius) {

    Entity character = em.createEntity();
    em.addComponent<Velocity>(character, velocity);
    em.addComponent<Position>(character, position);
    em.addComponent<Sides>(character, numberOfSides);
    em.addComponent<Color>(character, color);
    em.addComponent<Type>(character, type );
    em.addComponent<Visible>(character, true);
    em.addComponent<Rotation>(character, 0.f,rotation);
    em.addComponent<Radius>(character, radius);
    if (type ==0){
        em.addComponent<InputState>(character);
        em.addComponent<PlayerControl>(character);
    }


}

sf::Vector2f Factories::getRandomSpawnPosition( sf::Vector2u& winSize)  {
    auto x = Random::get<float>(10.f, static_cast<float>(winSize.x) - 10.f);
    auto y = Random::get<float>(10.f, static_cast<float>(winSize.y) - 10.f);
    return {x, y};
}