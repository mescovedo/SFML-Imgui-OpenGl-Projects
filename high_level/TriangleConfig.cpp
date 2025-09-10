//
// Created by mats_ on 25/08/2025.
//

#include "TriangleConfig.h"
#include "imgui.h"
#include "SFML/Graphics/ConvexShape.hpp"

void TriangleConfig::draw(sf::RenderWindow &window) {
    if (!visible) {return;}
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f , 0.f));
    triangle.setPoint(1, sf::Vector2f(size, 0.f));
    triangle.setPoint(2, sf::Vector2f(size/2.f, size));
    triangle.setFillColor(color);
    triangle.setPosition(position);
    window.draw(triangle);
}

void TriangleConfig::showImgui() {
    ImGui::PushID(name.c_str());
    ImGui::Text("Triangle: %s",  name.c_str());
    ImGui::Checkbox("Visible", &visible);
    ImGui::SliderFloat("Size", &size, 0.0f, 200.0f);
    ImGui::PopID();
}

void TriangleConfig::update(const sf::RenderWindow &window) {
    if (!visible) return;
    position += velocity;

    sf::Vector2u winSize = window.getSize();

    if (position.x  < 0 || position.x + size > static_cast<float>(winSize.x)) {
        velocity.x *= -1;

    }

    if (position.y  < 0 || position.y + size > static_cast<float>(winSize.y)) {
        velocity.y *= -1;
    }
}