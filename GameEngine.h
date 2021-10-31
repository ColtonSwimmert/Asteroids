#include "EntityHandler.h"

class GameEngine
{
public:
    static unsigned int playerCount;

    GameEngine(sf::RenderWindow *gameWindow);
    void updateGame();
    void detectCollisions();
    void KeyPressed(const short &code);
    void KeyReleased(const short &code);
    void draw();

private:
    sf::RenderWindow *window;
    EntityHandler eHandler;
    std::shared_ptr<GameObject> player;
    bool left = false, right = false, up = false, down = false;
};