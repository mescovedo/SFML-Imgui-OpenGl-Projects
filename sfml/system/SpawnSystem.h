//
// Created by mats_ on 12/09/2025.
//

#pragma once

#include "entity/EntityManager.h"

class SpawnSystem {

private:

    int timer;

public:

    void spawn(EntityManager &em);
    void startTimer();

};
