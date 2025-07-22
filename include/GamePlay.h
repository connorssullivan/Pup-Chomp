#pragma once

#include <memory>
#include <array>


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Config.h"
#include "State.h"
#include "Game.h"
#include "Snake.h"

class Context;

class GamePlay : public Engine::State
{
    private:
        std::shared_ptr<Context> m_context;

        std::optional<sf::Text> m_scoreText;
        int m_score;

        bool m_isPaused;

        std::optional<sf::Sprite> m_grass;
        std::optional<sf::Sprite> m_food;
        std::array<std::optional<sf::Sprite>, 4> m_walls;

        std::optional<Snake> m_snake;

        sf::Vector2f m_snakeDirection;

        sf::Time m_elapsedTime;

    public:
        GamePlay(std::shared_ptr<Context>& context);
        ~GamePlay();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
        void Pause() override;
        void Start() override;


};