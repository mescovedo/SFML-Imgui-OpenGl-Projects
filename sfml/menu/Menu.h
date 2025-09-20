
#pragma once

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Menu
{

public:
    void renderMenu(sf::RenderWindow& window, sf::Font& font, int selectedOption);
};
