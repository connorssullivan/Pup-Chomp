#pragma once

#include <iostream>
#include <memory>


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Config.h"
#include "AssetMan.h"
#include "StateMan.h"
#include "MainMenu.h"

enum AssetID
{
    MAIN_FONT = 0,
    GRASS,
    FOOD,
    WALL,
    SNAKE,
    DOG_HEAD,
    DOG_TAIL,
    MAIN_BACKGROUND,
    MAX_ASSET_ID,
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    : m_assets {std::make_unique<Engine::AssetMan>()}
    , m_states {std::make_unique<Engine::StateMan>()}
    , m_window {std::make_unique<sf::RenderWindow>()}
    {}
};


class Game
{
    private:
        std::shared_ptr<Context> m_context;
        const sf::Time TIME_PER_FRAME { sf::seconds(1.f/60.f) }; //Run 60 frames per second
        sf::Music bgMusic;

    public:
        Game();
        ~Game();

        void Run();
};