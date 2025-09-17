#include "MovementSystem.h"
#include "component/Moviment.h"
#include "component/Shape.h"

void MovementSystem::update(EntityManager &em, float dt, sf::Vector2u winSize) {
    auto entities = em.getEntities();

    for (auto e : entities) {

        auto& pos = em.getComponent<Position>(e)->value;
        auto& velo = em.getComponent<Velocity>(e)->value;
        auto angle = em.getComponent<Rotation>(e);
        auto& radius = em.getComponent<Radius>(e)->value;

        if (em.getComponent<Type>(e)->value == 0) {
            auto& input = *em.getComponent<InputState>(e);

            velo = {0.f, 0.f};

            if (input.up)    velo.y = -200.f * dt;
            if (input.down)  velo.y =  200.f * dt;
            if (input.left)  velo.x = -200.f * dt;
            if (input.right) velo.x =  200.f * dt;

        }


        pos += velo;

        angle->angle += angle->rotation/5;


        if (pos.x  < 0 || pos.x + radius*2 > winSize.x) {
            velo.x *= -1;

        }

        if (pos.y < 0 || pos.y + radius*2 > winSize.y) {
            velo.y *= -1;
        }
    }
}