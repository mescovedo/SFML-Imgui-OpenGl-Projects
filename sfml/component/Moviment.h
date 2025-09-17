//
// Created by mats_ on 11/09/2025.
//

#pragma once

#include "SFML/System/Vector2.hpp"

struct Velocity {
    sf::Vector2f value;
};

struct Position {
    sf::Vector2f value;
};

struct Rotation {
    float angle;
    float rotation;
};

struct InputState {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool mouseLeftClick = false;
    bool mouseRightClick = false;
};

struct PlayerControl {};

