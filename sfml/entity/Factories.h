//
// Created by mats_ on 11/09/2025.
//

#pragma once

#include "Entity.h"
#include "EntityManager.h"

class Factories {

public:

    Entity* createEntityCharacter(EntityManager em);
    Entity* createEntityShape(const EntityManager em);
    Entity* createEntityCircle(const EntityManager em);
    Entity* createEntityTriangle(const EntityManager em);

};



