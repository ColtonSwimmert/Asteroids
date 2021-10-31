#include "GameEngine.h"

GameEngine::GameEngine(sf::RenderWindow *gameWindow)
{

    std::cout << "Game Engine Initialized";
    player = std::make_shared<GameObject>(10.f, 3, 200, 200);
    eHandler.appendEntity(player);

    //player->shape->setPosition(player->physics.posX, player->physics.posY);
    float radius = player->shape->getRadius();
    std::cout << radius << "\n";
    player->shape->setOrigin(radius, radius);
    player->physics.setPosition(player->physics.posX, player->physics.posY);
    player->physics.radius = radius;
    window = gameWindow;

    eHandler.addEntity(5, 100, 100, 0, 0); //static asteroid for testing
}

void GameEngine::updateGame()
{
    // update rotation of player
    sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    float currentRotation = player->shape->getRotation();
    const float PI = 3.141559265;
    float dx = player->physics.posX - mousePosition.x;
    float dy = player->physics.posY - mousePosition.y;
    float rotation = (atan2(dy, dx)) * 180 / PI;
    player->shape->setRotation(rotation + 180);

    //delete dead entities
    eHandler.deleteEntities();
    //frame update
    eHandler.updateEntities();

    //draw entities
    for (auto entity : eHandler.entities)
    {
        window->draw(*entity->shape);
    }

    int chance = rand() % 100 + 1;
    //int chance = 0;

    if (chance == 100)
    {
        // 1 in 4 chance to spawn a asteroid

        float randomVelocityX = rand() % 5 - 2; // [-3 , 3]
        float randomVelocityY = rand() % 5 - 2; // [-3 , 3]

        float randomPosX = rand() % 400; // [0 , 400]
        float randomPosY = rand() % 400; // [0 , 400]

        eHandler.addEntity(5, randomPosX, randomPosY, randomVelocityX, randomVelocityY);
    }
}

void GameEngine::KeyPressed(const short &code)
{

    switch (code)
    {
    case sf::Keyboard::Left:
    case sf::Keyboard::A:
        if (left)
            return;
        left = true;
        player->physics.velocityX -= 1;
        break;
    case sf::Keyboard::Right:
    case sf::Keyboard::D:
        if (right)
            return;
        right = true;
        player->physics.velocityX += 1;
        break;
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
        if (up)
            return;
        player->physics.velocityY -= 1;
        up = true;
        break;
    case sf::Keyboard::Down:
    case sf::Keyboard::S:
        if (down)
            return;
        down = true;
        player->physics.velocityY += 1;
        break;
    case sf::Keyboard::Space:
        std::cout << player->physics.posX << " " << player->physics.posY << "\n";

        sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        float aimDirX = mousePosition.x - player->physics.posX;
        float aimDirY = mousePosition.y - player->physics.posY;
        float angle = atan2f(aimDirY, aimDirX);
        float x = std::cos(angle);
        float y = std::sin(angle);

        std::cout << "Velocities: " << x << " " << y << "\n";

        int radiusOffsetX = (player->physics.radius + 1) * x;
        int radiusOffsetY = (player->physics.radius + 1) * y;

        eHandler.addEntity(2, player->physics.posX + radiusOffsetX + player->physics.velocityX, player->physics.posY + radiusOffsetY + player->physics.velocityY, x, y);
        break;
    }
}

void GameEngine::KeyReleased(const short &code)
{
    switch (code)
    {
    case sf::Keyboard::Left:
    case sf::Keyboard::A:
        left = false;
        player->physics.velocityX += 1;
        break;
    case sf::Keyboard::Right:
    case sf::Keyboard::D:
        right = false;
        player->physics.velocityX -= 1;
        break;
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
        up = false;
        player->physics.velocityY += 1;
        break;
    case sf::Keyboard::Down:
    case sf::Keyboard::S:
        down = false;
        player->physics.velocityY -= 1;
        break;
    case sf::Keyboard::Space:
        break;
    default:
        // not move key
        break;
    }
}