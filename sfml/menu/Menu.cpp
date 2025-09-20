
#include "Menu.h"

#include "SFML/Graphics/Text.hpp"
#include "system/Sound.h"

void Menu::renderMenu(sf::RenderWindow& window, sf::Font& font, int selectedOption)
{
    sf::Text title("Shape Shooter", font, 48);
    title.setPosition(200, 100);
    title.setFillColor(sf::Color::White);

    sf::Text play("Play", font, 32);
    sf::Text exit("Exit", font, 32);

    play.setPosition(250, 200);
    exit.setPosition(250, 260);

    play.setFillColor(selectedOption == 0 ? sf::Color::Green : sf::Color::White);
    exit.setFillColor(selectedOption == 1 ? sf::Color::Green : sf::Color::White);

    window.draw(title);
    window.draw(play);
    window.draw(exit);

}
