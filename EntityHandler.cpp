#include "EntityHandler.h"

EntityHandler::EntityHandler()
{

    std::cout << "Entity Handler Generated!\n";
}

void EntityHandler::updateEntities()
{
    int index = 0;
    for (auto &entity : entities)
    {
        entity->physics.updatePosition();
        detectCollision(index);
        entity->shape->setPosition(entity->physics.posX, entity->physics.posY);
        index++;
    }
}

void EntityHandler::deleteEntities()
{
    for (auto entity : removeEntities)
    {
        int index = 0;
        for (; index < entities.size(); index++)
        {
            if (entity->entityID == entities[index]->entityID)
            {
                break;
            }
        }
        entities.erase(entities.begin() + index);
    }

    removeEntities.clear();
}

void EntityHandler::appendEntities()
{
    // add entities to map and entities vector

    for (auto entity : newEntities)
    {
        entities.push_back(entity);
    }
    newEntities.clear();
}

void EntityHandler::detectCollision(const int index)
{
    const auto &selectedEntity = entities[index];
    float distanceX = 0;
    float distanceY = 0;

    for (int i = index + 1; i < entities.size(); i++)
    {
        const auto &current = entities[i];

        distanceX = pow(selectedEntity->physics.posX - current->physics.posX, 2);
        distanceY = pow(selectedEntity->physics.posY - current->physics.posY, 2);
        float sumRadius = pow(selectedEntity->physics.radius + current->physics.radius, 2);

        if (distanceX + distanceY < sumRadius * .9)
        {
            std::cout << distanceX << " " << distanceY << " " << sumRadius << "\n";
            // collision! obs will be removed next frame
            std::cout << "Collision of objs!\n";
            std::cout << selectedEntity->physics.posX << " " << selectedEntity->physics.posX << " " << current->physics.posX << " " << selectedEntity->physics.posY << "\n";
            removeEntities.push_back(selectedEntity);
            removeEntities.push_back(current);
            return;
        }
    }
}

std::shared_ptr<GameObject> EntityHandler::addEntity(const int entityID, float posX, float posY, float velocityX = 0, float velocityY = 0)
{
    std::shared_ptr<GameObject> returnVal(nullptr);
    float OffsetX = 0;
    float OffsetY = 0;
    switch (entityID)
    {
    case 1:
        returnVal = std::make_shared<GameObject>(posX, posY);

        //set to go down right for now
        returnVal->physics.velocityX = 1;
        returnVal->physics.velocityY = 1;
        return returnVal;

    case 2:
    case 3:
    case 4:
        // really dumb switch statment but leaving until alpha ver

        switch (entityID)
        {
        case 2:
            returnVal = std::make_shared<GameProjectiles::Projectile>(posX, posY);
            break;
        case 3:
            //newProjectile = new GameProjectiles::Missle(posX, posY);
            returnVal = std::make_shared<GameProjectiles::Projectile>(posX, posY);
            break;
        case 4:
            //newProjectile = new GameProjectiles::Rocket(posX, posY);
            returnVal = std::make_shared<GameProjectiles::Projectile>(posX, posY);
            break;
        }

        returnVal->physics.posX += velocityX * returnVal->physics.radius;
        returnVal->physics.posY += velocityY * returnVal->physics.radius;
        returnVal->shape->setPosition(returnVal->physics.posX, returnVal->physics.posY);

        //fast speed for testing
        returnVal->physics.velocityX = velocityX * 5;
        returnVal->physics.velocityY = velocityY * 5;

        entities.push_back(returnVal);

        if (entityMap.count(entityID) >= 1)
        {
            entityMap[entityID].push_back(returnVal);
        }
        else
        {
            entityMap[entityID] = {returnVal};
        }

        return returnVal;

    case 5:
        //build asteroid
        returnVal = std::make_shared<GameObject>(10.f, 5, posX, posY);
        returnVal->physics.velocityX = velocityX;
        returnVal->physics.velocityY = velocityY;
        entities.push_back(returnVal);
        return returnVal;
    }

    return returnVal;
}

void EntityHandler::appendEntity(std::shared_ptr<GameObject> &gameObject)
{
    //add a pre built object
    entities.push_back(gameObject);
}
