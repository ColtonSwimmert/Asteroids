#include "GameComponent.h"

GameProjectiles::Projectile::Projectile(float posX, float posY)
{
    // display that a projectile was created
    std::cout << "Created Projectile\n";

    projectileID = 0; // 0 means null in this case
    shape = std::make_shared<sf::CircleShape>(3, 7);
    float radius = shape->getRadius();
    //shape->setOrigin(radius, radius);
    shape->setPosition(posX, posY);
    physics.setPosition(posX, posY);
    physics.radius = radius;
}

void GameProjectiles::Projectile::on_hit()
{
    std::cout << "collision with another object!\n";
}

GameProjectiles::Missle::Missle(float posX, float posY) : Projectile(posX, posY)
{
    std::cout << "Created Missle!\n";
    projectileID = 1;
    shape = std::make_shared<sf::CircleShape>(3, 5);
}

GameProjectiles::Rocket::Rocket(float posX, float posY) : Projectile(posX, posY)
{
    std::cout << "Created Rocket!\n";

    projectileID = 2;
    shape = std::make_shared<sf::CircleShape>(3, 7);
}
