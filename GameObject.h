#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <map>
#include <iterator>
#include <memory>
#include <random>
#include <cmath>

class EntityPhysics
{
public:
    EntityPhysics();
    EntityPhysics(float startPosX, float startPosY);

    void setPosition(float x, float y);
    void updatePosition();
    float radius = 0;
    float posX = 0;
    float posY = 0;
    float velocityX = 0;
    float velocityY = 0;
};

class GameObject
{
public:
    static unsigned int entityCount;
    GameObject();
    GameObject(float size, int edges);
    GameObject(float size, int edges, float posX, float posY);

    void setPosition(float posX, float posY);
    void updatePosition();

    EntityPhysics physics;
    std::shared_ptr<sf::CircleShape> shape;
    std::string name;
    unsigned int entityID = 0;
};