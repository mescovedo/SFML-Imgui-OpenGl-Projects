//
// Created by mats_ on 10/09/2025.
//

#pragma once

#include <algorithm>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

#include "Entity.h"

class EntityManager {
public:
    EntityManager() = default;
    ~EntityManager() = default;

    Entity createEntity();
    void destroyEntity(Entity entity);


    template <typename T, typename... Args>
        T& addComponent(Entity e, Args&&... args) {
        auto& storage = getStorage<T>();
        return storage.add(e, T{std::forward<Args>(args)...});
    }

    template<typename T>
    T* getComponent(Entity e) {
        auto& storage = getStorage<T>();
        return storage.get(e);
    }

    template<typename T>
    bool hasComponent(Entity e) {
        auto& storage = getStorage<T>();
        return storage.has(e);
    }

    const std::vector<Entity>& getEntities() const { return m_entities; }

private:
    struct IStorage {
        virtual ~IStorage() = default;
        virtual void remove(Entity e) = 0;
    };

    template<typename T>
    struct Storage : IStorage {
        std::unordered_map<Entity, T> data;

        T& add(Entity e, T&& comp) {
            data[e] = std::move(comp);
            return data[e];
        }

        T* get(Entity e) {
            auto it = data.find(e);
            return (it != data.end()) ? &it->second : nullptr;
        }

        bool has(Entity e) {
            return data.find(e) != data.end();
        }

        void remove(Entity e) override {
            data.erase(e);
        }
    };

    template<typename T>
    Storage<T>& getStorage() {
        auto type = std::type_index(typeid(T));
        if (!m_components.count(type)) {
            m_components[type] = std::make_unique<Storage<T>>();
        }
        return *static_cast<Storage<T>*>(m_components[type].get());
    }

    Entity m_lastId{0};
    std::vector<Entity> m_entities;
    std::unordered_map<std::type_index, std::unique_ptr<IStorage>> m_components;
};
