//
// Created by mats_ on 12/09/2025.
//

#include "SpawnSystem.h"
#include "entity/Factories.h"

void SpawnSystem::spawn(EntityManager &em) {

    if (timer > 150){

        Factories::createEntityTriangle(em);
        Factories::createEntityCircle(em);
        Factories::createEntityCharacter(em);

        timer = 0;
    }
    timer++;
}

void SpawnSystem::startTimer() {

    timer = 0;
}