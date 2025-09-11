//
// Created by mats_ on 25/08/2025.
//

#include "RectangleConfig.h"
#include "imgui.h"
#include "SFML/Graphics/RectangleShape.hpp"

void RectangleConfig::draw(sf::RenderWindow& window) {
    if (!visible) {return;}
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    window.draw(rectangle);
}

void RectangleConfig::showImgui() {
    ImGui::PushID(name.c_str());
    ImGui::Text("Rectangle: %s", name.c_str());
    ImGui::Checkbox("Visible", &visible);
    ImGui::SliderFloat("Width", &width, 0.0f, 200.0f);
    ImGui::SliderFloat2("Height", &height, 0.0f, 200.0f);
    ImGui::PopID();
}

void RectangleConfig::update(const sf::RenderWindow &window) {
    if (!visible) return;
    position += velocity;

    sf::Vector2u winSize = window.getSize();

    if (position.x < 0 || position.x +  width> static_cast<float>(winSize.x)) {
        velocity.x *= -1;

    }

    if (position.y  < 0 || position.y + height > static_cast<float>(winSize.y)) {
        velocity.y *= -1;
    }
}
