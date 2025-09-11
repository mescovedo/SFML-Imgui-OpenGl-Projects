//
// Created by mats_ on 25/08/2025.
//

#pragma once
#include "ShapeConfig.h"


class TriangleConfig : public ShapeConfig{
    public:
        float size = 100.0f;
        void draw(sf::RenderWindow &window) override;
        void showImgui() override;
        void update(const sf::RenderWindow &window) override;

};
