#include "GameComponent.h"

class EntityHandler
{
public:
    EntityHandler();

    void updateEntities();
    void deleteEntities();
    void appendEntities();
    void detectCollision(const int index);
    std::shared_ptr<GameObject> addEntity(const int entityID, float posX, float posY, float velocityX, float velocityY);
    void appendEntity(std::shared_ptr<GameObject> &gameObject);
    std::vector<std::shared_ptr<GameObject>> entities;
    std::vector<std::shared_ptr<GameObject>> newEntities;
    std::vector<std::shared_ptr<GameObject>> removeEntities;

    std::map<int, std::vector<std::shared_ptr<GameObject>>> entityMap;
};