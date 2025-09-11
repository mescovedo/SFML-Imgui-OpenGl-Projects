//
// Created by mats_ on 25/08/2025.
//

#include "SquareConfig.h"

#include "imgui.h"
#include "../external/sfml/include/SFML/Graphics/RectangleShape.hpp"

void SquareConfig::draw(sf::RenderWindow &window) {
    if (!visible){return;}
    sf::RectangleShape square(sf::Vector2f(size, size));
    square.setFillColor(color);
    square.setPosition(position);
    window.draw(square);
}

void SquareConfig::showImgui() {
    ImGui::PushID(name.c_str());
    ImGui::Text("Square: %s", name.c_str());
    ImGui::Checkbox("Visible", &visible);
    ImGui::SliderFloat("Size", &size, 0.0f, 200.0f);
    ImGui::PopID();

}

void SquareConfig::update(const sf::RenderWindow &window) {
    if (!visible) return;
    position += velocity;

    const sf::Vector2u winSize = window.getSize();

    if (position.x - size < 0 || position.x > static_cast<float>(winSize.x)) {
        velocity.x *= -1;

    }

    if (position.y - size < 0 || position.y > (float)winSize.y) {
        velocity.y *= -1;
    }
}
