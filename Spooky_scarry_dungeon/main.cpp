#include <tilemap.h>

int main()
{
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");
        sf::View view(sf::FloatRect(300.f, 300.f, 170.f, 170.f));

        // create the tilemap from th   e level definition
        TileMap map;
        map.setScale(1.0, 1.0);
        if (!map.load("C:/Users/szymo/OneDrive/Game_PSiO/SSD/Grafiki/tileset.png", sf::Vector2u(16, 16), "Map2.txt", 62, 66))
            return -1;

        // run the main loop
        sf::Clock dtClock;
        float dt = 0.0f;

        while (window.isOpen())
        {

            dt = dtClock.restart().asSeconds();
            // handle events
             window.setFramerateLimit(60);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            sf::Clock clock;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                view.move(100*dt, 0*dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                view.move(-100*dt, 0*dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                view.move(0*dt, -100*dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                view.move(0*dt, 100*dt);
            }

            std::cout << 1 / dt<<std::endl;

            clock.restart();

            // draw the map
            window.clear();
            window.setView(view);
            window.draw(map);
            window.display();
        }

        return 0;
}
