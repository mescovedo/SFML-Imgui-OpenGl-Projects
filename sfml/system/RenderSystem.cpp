#include <optional>
#include <cmath>
#include "RenderSystem.h"
#include "component/Shape.h"
#include "component/Moviment.h"
#include "SFML/Graphics/CircleShape.hpp"

void RenderSystem::update(EntityManager &em, sf::RenderWindow &window) {

    static sf::Vector2u winSize = window.getSize();


    removeInvisible(em);

    for(auto e: em.getEntities()){

        auto& visible = em.getComponent<Visible>(e)->value;

        if (!visible) continue;

        auto& pos = em.getComponent<Position>(e)->value;
        auto& sides = em.getComponent<Sides>(e)->value;
        auto& color = em.getComponent<Color>(e)->value;
        auto& angle = em.getComponent<Rotation>(e)->angle;


        sf::CircleShape shape(20, sides);
        shape.setFillColor(color);
        shape.setPosition(pos);
        shape.setRotation(angle);

        sf::Vector2f vecRadius = sf::Vector2f(20, 20);

        sf::Vector2f rotatedPos1 = pos;


        float angleRad = angle * 3.14159265f / 180.f;


        rotatedPos1.x += vecRadius.x * cos(angleRad);
        rotatedPos1.y += vecRadius.y * sin(angleRad);


        sf::CircleShape collider(20,100);
        collider.setPosition(pos);
        collider.setRotation(angle);
        collider.setFillColor(sf::Color::Transparent);
        collider.setOutlineThickness(1.f);
        collider.setOutlineColor(sf::Color::Green);
        window.draw(collider);


        window.draw(shape);
    }

}


void RenderSystem::removeInvisible(EntityManager &em) {

    std::vector<Entity> toRemove;
    for (auto e : em.getEntities()) {
        if (!em.getComponent<Visible>(e)->value) {
            toRemove.push_back(e);
        }
    }
    for (auto e : toRemove) {
        em.destroyEntity(e);
    }
}

