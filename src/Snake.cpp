#include "Snake.h"


#include "Snake.h"
#include "Config.h"

Snake::Snake()
{
    // Fill body with placeholders
    for (int i = 0; i < 4; ++i)
        m_body.emplace_back(std::nullopt);  // empty optional for now

    m_head = --m_body.end();
    m_tail = m_body.begin();
}

Snake::~Snake() {}

void Snake::Init(const sf::Texture& headTexture, const sf::Texture& bodyTexture)
{
    float x { static_cast<float>(Config::PIX_SIZE) };
    int head { static_cast<int>(m_body.size() - 1) };
    int i { 0 };

    for (auto& piece : m_body)
    {
        if (i == head)
            piece.emplace(headTexture);
        else
            piece.emplace(bodyTexture);

        const sf::Texture& tex = piece->getTexture(); 

        // Scaling 
        piece->setScale({
            16.f / static_cast<float>(tex.getSize().x),
            16.f / static_cast<float>(tex.getSize().y)
        });

        piece->setPosition({ x, static_cast<float>(Config::PIX_SIZE) });
        x += static_cast<float>(Config::PIX_SIZE);
        i++;
    }
}



void Snake::Move(const sf::Vector2f& direction)
{
    if (m_body.size() < 2) return;

    // Save current head position
    sf::Vector2f prevPos = m_body.back()->getPosition();

    // Move each segment (except the head) to the position of the next
    auto it = m_body.begin();
    auto nextIt = std::next(it);
    while (nextIt != m_body.end()) {
        if (nextIt->has_value())
            (*it)->setPosition((*nextIt)->getPosition());

        ++it;
        ++nextIt;
    }

    // Move head to new position
    m_body.back()->setPosition(prevPos + direction);
}


bool Snake::IsOn(const sf::Sprite& other) const
{
    // Implement if needed
    return false;
}

void Snake::Grow(const sf::Vector2f& direction)
{
    // Implement if needed
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& piece : m_body)
    {
        if (piece.has_value())
            target.draw(*piece, states);
    }
}
