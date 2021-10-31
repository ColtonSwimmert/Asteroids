#include "GameObject.h"

EntityPhysics::EntityPhysics()
{
    //new object is created
    posX = 0, posY = 0, velocityX = 0, velocityY = 0;
}

EntityPhysics::EntityPhysics(float startPosX, float startPosY)
{
    posX = startPosX, posY = startPosY, velocityX = 0, velocityY = 0;
}

void EntityPhysics::setPosition(float x, float y)
{
    posX = x, posY = y;
}

void EntityPhysics::updatePosition()
{
    posX += velocityX;
    posY += velocityY;
}

GameObject::GameObject()
{
    entityID = entityCount;
    entityCount++;
    std::cout << "New object created! default constructor!\n";
    shape = std::make_shared<sf::CircleShape>(5.f, 3);
    shape->setFillColor(sf::Color::Black);
    shape->setOutlineColor(sf::Color::White);
    shape->setOutlineThickness(1);
    shape->setPosition(200, 200);
    float radius = shape->getRadius();
    shape->setOrigin(radius, radius);
    physics.radius = radius;
}

GameObject::GameObject(float size, int edges)
{
    //created new object
    entityID = entityCount;
    entityCount++;
    std::cout << "New object created! " << this << "\n";
    shape = std::make_shared<sf::CircleShape>(10.f, 3);

    shape->setFillColor(sf::Color::Black);
    shape->setOutlineColor(sf::Color::White);
    shape->setOutlineThickness(1);
    float radius = shape->getRadius();
    float pos = 200;
    shape->setPosition(pos, pos);
    shape->setOrigin(radius, radius);
    physics.radius = radius;
}

GameObject::GameObject(float size, int edges, float posX, float posY)
{
    entityID = entityCount;
    entityCount++;
    std::cout << "New object created(" << this << ") at pos(" << posX << "," << posY << ")\n";
    shape = std::make_shared<sf::CircleShape>(size, edges);

    float radius = shape->getRadius();
    shape->setFillColor(sf::Color::Black);
    shape->setOutlineColor(sf::Color::White);
    shape->setOutlineThickness(1);
    shape->setPosition(posX, posY);
    shape->setOrigin(radius, radius);
    physics.posX = posX;
    physics.posY = posY;
    physics.radius = radius;
}

void GameObject::setPosition(float posX, float posY)
{
    physics.posX = posX;
    physics.posY = posY;
}

void GameObject::updatePosition()
{
    physics.posX += physics.velocityX;
    physics.posY += physics.velocityY;
}

unsigned int GameObject::entityCount = 0;
