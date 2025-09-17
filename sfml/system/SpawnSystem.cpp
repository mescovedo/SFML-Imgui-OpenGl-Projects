//
// Created by mats_ on 12/09/2025.
//

#include "SpawnSystem.h"
#include "entity/Factories.h"
#include "utils/Random.h"
#include "component/Shape.h"

void SpawnSystem::spawn(EntityManager &em, sf::Vector2u& winSize) {

    if (timer > spawn_limit){

        bool playerExists = false;

        for (auto e : em.getEntities()) {
            if (em.getComponent<Type>(e)->value == 0) {
                playerExists = true;
                break;
            }
        }

        Factories::createEntityTriangle(em, winSize);
        Factories::createEntityCircle(em, winSize);
        Factories::createEntitySquare(em, winSize);
        if (!playerExists) {
            Factories::createEntityCharacter(em, winSize);
        }


        spawn_limit = Random::get<>(100 , 200);
        timer =0;
    }
    timer++;
}

void SpawnSystem::startTimer() {

    timer = 0;
    spawn_limit = 150;
}