//
// Created by mats_ on 25/08/2025.
//

#include "CircleConfig.h"
#include "imgui.h"
#include "SFML/Graphics/CircleShape.hpp"

void CircleConfig::draw(sf::RenderWindow& window) {
    if (!visible) return;
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(position);
    window.draw(circle);
}

void CircleConfig::showImgui() {
    ImGui::PushID(name.c_str());
    ImGui::Text("Circle: %s", name.c_str());
    ImGui::Checkbox("Visible", &visible);
    ImGui::SliderFloat("Radius", &radius, 0.0f, 200.0f);
    ImGui::DragFloat2("Velocity", reinterpret_cast<float *>(&velocity), 0.1f);
    ImGui::PopID();
}

void CircleConfig::update(const sf::RenderWindow &window) {
    if (!visible) return;
    position += velocity;

    sf::Vector2u winSize = window.getSize();

    if (position.x  < 0 || position.x + radius*2 > static_cast<float>(winSize.x)) {
        velocity.x *= -1;

    }

    if (position.y < 0 || position.y + radius*2 > static_cast<float>(winSize.y)) {
        velocity.y *= -1;
    }

}