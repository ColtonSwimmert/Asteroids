#include "GameEngine.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Asteroids!");

    GameEngine asteroidEngine(&window);

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                asteroidEngine.KeyPressed(event.key.code);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                asteroidEngine.KeyReleased(event.key.code);
            }
        }

        window.clear();
        asteroidEngine.updateGame();
        window.display();
    }

    return 0;
}