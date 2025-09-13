//
// Created by mats_ on 12/09/2025.
//

#include <optional>
#include "RenderSystem.h"
#include "component/Shape.h"
#include "component/Moviment.h"
#include "SFML/Graphics/CircleShape.hpp"

void RenderSystem::update(EntityManager &em, sf::RenderWindow &window, SpawnSystem &spawnSystem) {

    sf::Vector2u winSize = window.getSize();

    for(auto e: em.getEntities()){

        auto& pos = em.getComponent<Position>(e)->value;
        auto& velo = em.getComponent<Velocity>(e)->value;
        auto& sides = em.getComponent<Sides>(e)->value;
        auto& color = em.getComponent<Color>(e)->value;
        auto& type = em.getComponent<Type>(e)->value;
        auto& visible = em.getComponent<Visible>(e)->value;
        auto& angle = em.getComponent<Rotation>(e)->angle;
        auto& rotation = em.getComponent<Rotation>(e)->rotation;


        setPosition(pos, velo, winSize,visible, type,20, angle, rotation);


        sf::CircleShape shape(20, sides);
        shape.setFillColor(color);
        shape.setPosition(pos);
        shape.setRotation(angle);

        window.draw(shape);
    }

    spawnSystem.spawn(em);
}

void RenderSystem::setPosition(sf::Vector2f& position, sf::Vector2f& velocity, sf::Vector2u& winSize, bool visible, int tag, int radius, float &angle , float &rotation ) {

    if (!visible) return;


            position += velocity;

            angle += rotation/5;


            if (position.x  < 0 || position.x + radius*2 > static_cast<float>(winSize.x)) {
                velocity.x *= -1;

            }

            if (position.y < 0 || position.y + radius*2 > static_cast<float>(winSize.y)) {
                velocity.y *= -1;
            }

}

