//
// Created by mats_ on 10/09/2025.
//

#include "EntityManager.h"

Entity EntityManager::createEntity() {
    Entity id = ++m_lastId;
    m_entities.push_back(id);
    return id;
}

void EntityManager::destroyEntity(Entity entity) {
    for (auto& [type, storage] : m_components) {
        storage->remove(entity);
    }
    m_entities.erase(
    std::remove(m_entities.begin(), m_entities.end(), entity),
    m_entities.end()
);

}

