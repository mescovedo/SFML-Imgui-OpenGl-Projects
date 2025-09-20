#pragma once
#include <iostream>
#include <SFML/Audio/Music.hpp>

#include "State/GameState.h"

enum class GameState;

namespace sound
{
    class Sound
    {

    };

    static void initSound(sf::Music &menuMusic, sf::Music &gameMusic)
    {

        if (!menuMusic.openFromFile("assets/audio/Menu.ogg")) {
            std::cerr << "Erro ao carregar menu_music.ogg\n";
        }
        if (!gameMusic.openFromFile("assets/audio/Game.ogg")) {
            std::cerr << "Erro ao carregar game_music.ogg\n";
        }

        menuMusic.setLoop(true);
        gameMusic.setLoop(true);

        menuMusic.play();

    }

    static void changeMusic(sf::Music &menuMusic, sf::Music &gameMusic, GameState &currentState)
    {

        if (currentState == GameState::MENU)
        {
            menuMusic.stop();
            gameMusic.play();

        }
        else
        {
            menuMusic.play();
            gameMusic.stop();
        }
    }
}


