//
// Created by mats_ on 12/09/2025.
//

#include "SpawnSystem.h"
#include "entity/Factories.h"
#include "utils/Random.h"

void SpawnSystem::spawn(EntityManager &em, sf::Vector2u& winSize) {

    if (timer > 150){

        Factories::createEntityTriangle(em, winSize);
        Factories::createEntityCircle(em, winSize);
        Factories::createEntityCharacter(em, winSize);

        timer = Random::get<>(100 , 200);
    }
    timer++;
}

void SpawnSystem::startTimer() {

    timer = 0;
}