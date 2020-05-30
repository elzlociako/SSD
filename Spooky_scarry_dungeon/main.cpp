#include <tilemap.h>

int main()
{
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");

        // create the tilemap from the level definition
        TileMap map;
        map.setScale(2.0, 2.0);
        if (!map.load("C:/Users/szymo/OneDrive/Game_PSiO/SSD/Grafiki/tileset.png", sf::Vector2u(16, 16), "Map.txt", 7, 7))
            return -1;

        // run the main loop
        while (window.isOpen())
        {
            // handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }

            // draw the map
            window.clear();
            window.draw(map);
            window.display();
        }

        return 0;
}
