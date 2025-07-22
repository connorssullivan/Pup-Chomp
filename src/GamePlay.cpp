#include "GamePlay.h"
#include <string>
#include <stdlib.h>
#include <time.h>

#include "GameOver.h"
#include "PauseGame.h"


GamePlay::GamePlay(std::shared_ptr<Context>& context)
: m_context {context}
, m_snakeDirection {16, 0}
, m_elapsedTime {sf::Time::Zero}
{
    srand(time(nullptr));
}

GamePlay::~GamePlay()
{

}

void GamePlay::Init() 
{
    // These now work because AddTexture takes const std::string&
    std::string grassPath = "assets/textures/grass.png";
    m_context->m_assets->AddTexture(GRASS, grassPath, true);

    std::string foodPath = "assets/textures/food.png";
    m_context->m_assets->AddTexture(FOOD,  foodPath);

    std::string wallPath = "assets/textures/wall.png";
    m_context->m_assets->AddTexture(WALL,  wallPath, true);

    std::string snakePath = "assets/textures/snake.png";
    m_context->m_assets->AddTexture(SNAKE, snakePath);

    std::string dogHead = "assets/textures/dogHead.png";
    m_context->m_assets->AddTexture(DOG_HEAD, dogHead);


    // Get the grass and food texture 
    const sf::Texture& grassTex = m_context->m_assets->getTexture(GRASS);
    const sf::Texture& foodTex = m_context->m_assets->getTexture(FOOD);
    const sf::Texture& wallTex = m_context->m_assets->getTexture(WALL);
    const sf::Texture& dogHeadTex = m_context->m_assets->getTexture(DOG_HEAD);

    for (auto& wall : m_walls)
    {
        wall.emplace(wallTex);
    }


    // Emplace the sprite with that texture (required in SFML 3)
    m_grass.emplace(grassTex);
    /*m_grass->setScale({
            16.f / static_cast<float>(grassTex.getSize().x),
            16.f / static_cast<float>(grassTex.getSize().y)
        });*/
    m_food.emplace(foodTex);


    // Apply full viewport rect to the grass sprite
    m_grass->setTextureRect(
        m_context->m_window->getViewport(m_context->m_window->getDefaultView())
    );

    // Create the walls
    m_walls[0]->setTextureRect(sf::IntRect({0, 0}, {Config::SCREEN_WIDTH, Config::WALL_THICKNESS}));
    m_walls[1]->setTextureRect(sf::IntRect({0, 0}, {Config::SCREEN_WIDTH, Config::WALL_THICKNESS}));
    m_walls[1]->setPosition({0, Config::SCREEN_HEIGHT -16});

    m_walls[2]->setTextureRect(sf::IntRect({0, 0}, {Config::WALL_THICKNESS, Config::SCREEN_HEIGHT}));
    m_walls[3]->setTextureRect(sf::IntRect({0, 0}, {Config::WALL_THICKNESS, Config::SCREEN_HEIGHT}));
    m_walls[3]->setPosition({Config::SCREEN_WIDTH - 16, 0});

    // Create food
    m_food->setPosition({Config::SCREEN_WIDTH / 2, Config::SCREEN_HEIGHT/2});

    // Create the snake
    m_snake.emplace();
    const sf::Texture& snakeTex = m_context->m_assets->getTexture(SNAKE);
    m_snake->Init(dogHeadTex,snakeTex);
    
}





void GamePlay::ProcessInput() 
{
    while (const std::optional<sf::Event> event = m_context->m_window->pollEvent())
    {
        if(event->is<sf::Event::Closed>())
            m_context->m_window->close();
        
        else if (event->is<sf::Event::KeyPressed>())
        {
            sf::Vector2f newDirection = m_snakeDirection;
            const auto& keyEvent = event->getIf<sf::Event::KeyPressed>();
            switch (keyEvent->code)
            {
            case sf::Keyboard::Key::Up:
                newDirection = {0.f, -16.f};
                break;
            case sf::Keyboard::Key::Down:
                newDirection = {0.f, 16.f};
                break;
            case sf::Keyboard::Key::Left:
                newDirection = {-16.f, 0.f};
                break;
            case sf::Keyboard::Key::Right:
                newDirection = {16.f, 0.f};
                break;
            case sf::Keyboard::Key::Escape:
                //TODO: Pause
                m_context->m_states->Add(std::make_unique<PauseGame>(m_context));
                break;
            default:
                break;
           }
           if (std::abs(m_snakeDirection.x) != std::abs(newDirection.x) ||
                std::abs(m_snakeDirection.y) != std::abs(newDirection.y))
            {
                m_snakeDirection = newDirection;
            }
        }
        
    }
}

void GamePlay::Update(sf::Time deltaTime) 
{
    m_elapsedTime += deltaTime;
    if (m_elapsedTime.asSeconds() > 0.1)
    {
        m_snake->Move(m_snakeDirection);

        for (auto& wall : m_walls)
        {
            if (m_snake->IsOn(wall.value()))
            {
            
                m_context->m_states->Add(std::make_unique<GameOver>(m_context), true);
                break;
            }
        }

        if (m_snake->IsOn(m_food.value()))
        {
            m_snake->Grow(m_snakeDirection); 
            
            float x { static_cast<float> (rand() % (Config::SCREEN_WIDTH)) };
            float y { static_cast<float> (rand() % (Config::SCREEN_HEIGHT)) };

            x = std::clamp<int>(rand() % (Config::SCREEN_WIDTH), 16, Config::SCREEN_WIDTH - 2*16);
            y = std::clamp<int>(rand() % (Config::SCREEN_HEIGHT), 16, Config::SCREEN_HEIGHT - 2*16);

            m_food.value().setPosition({x, y});
        }

        m_elapsedTime = sf::Time::Zero;
    }
}


void GamePlay::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(*m_grass);

   for (auto& wall : m_walls)
   {
        m_context->m_window->draw(*wall);
   }

    m_context->m_window->draw(*m_food);

    m_context->m_window->draw(*m_snake);

    m_context->m_window->display();

}

void GamePlay::Pause() 
{

}

void GamePlay::Start()
{

}
