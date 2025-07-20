#pragma once

#include <list>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


class Snake : public sf::Drawable
{
    private:
        std::list<std::optional<sf::Sprite>> m_body;
        std::list<std::optional<sf::Sprite>>::iterator m_head;
        std::list<std::optional<sf::Sprite>>::iterator m_tail;


    public:
        Snake();
        ~Snake();

        void Init(const sf::Texture& headTexture,const sf::Texture& bodyTexture);
        void Move(const sf::Vector2f& direction);
        bool IsOn(const sf::Sprite& other) const;
        void Grow(const sf::Vector2f& direction);

        void draw(sf::RenderTarget& target, sf::RenderStates stats) const override;
};