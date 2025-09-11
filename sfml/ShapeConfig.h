//
// Created by mats_ on 25/08/2025.
//
#pragma once
#include <string>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class ShapeConfig {
    public:
        std::string name;
        sf::Color color;
        sf::Vector2f position;
        bool visible;
        sf::Vector2f velocity;

        virtual ~ShapeConfig() = default;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void showImgui() = 0;
        virtual void update(const sf::RenderWindow& window) = 0;

};