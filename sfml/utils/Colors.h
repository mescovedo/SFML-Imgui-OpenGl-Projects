//
// Created by mats_ on 12/09/2025.
//

#include <map>
#include "SFML/Graphics/Color.hpp"

enum class GameColor{
    red,
    blue,
    gray,
    green,
    yellow
};

inline const std::map<GameColor, sf::Color>& ColorsMap ={
            {GameColor::red,   sf::Color(238, 11, 56)},
            {GameColor::blue,   sf::Color(11, 18, 238)},
            {GameColor::gray,   sf::Color(120, 120, 120)},
            {GameColor::green,   sf::Color(11, 238, 18)},
            {GameColor::yellow,   sf::Color(230, 238, 11)}
};

