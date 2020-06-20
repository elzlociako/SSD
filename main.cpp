#include <rooms.h>
#include <hud.h>
#include <bags.h>

int main()
{
        srand(time(NULL));
        //Window
        sf::RenderWindow  window(sf::VideoMode(1024, 768), "Spooky, Scarry Dungeon");
        window.setFramerateLimit(60);
//        window.setVerticalSyncEnabled(true);

        //View
        sf::View view;
        view.setCenter(sf::Vector2f(111.f, 991.f));
        view.setSize(1024.f/4, 768.f/4);

        //Sound
        sf::Music music;
        music.openFromFile("Muzyka/Music.wav");
        music.play();
        music.setLoop(true);

        //Map creation
        TileMap map;
        TileMap map2;

        //Player creation
        Hero player(sf::Vector2f(103.f, 983.f), sf::Vector2f(14.f, 17.f), "Grafiki/Characters/Archer/a1.png");

        //Lvls
        Rooms rooms;

        //Bag
        auto HP = std::make_unique<Bags>(sf::Vector2f(16.f, 16.f), "Grafiki/life1.png", 20);
        std::vector<std::unique_ptr<Bags>> bags;
        for(unsigned int i = 0; i < 2; i++){
             HP = std::make_unique<Bags>(sf::Vector2f(16.f, 16.f), "Grafiki/life1.png", 20);
             bags.emplace_back(std::move(HP));
         }

        bags[0]->setPosition(106.f, 458.f);
        bags[1]->setPosition(873.f, 458.f);

        //Hud
        HUD hud;
        hud.initFont();
        hud.initText();
        hud.initWinText();
        hud.initMENU();
        bool MENU_ON = true;

        //Map loading
        //-----------------------------------------------------------------------------------------------
        if (!map.load("Mapy/Map.txt"))
            return -1;

        if (!map2.load("Mapy/Map2.txt"))
            return -1;

        if (!map.loadColissionMap("Mapy/CollisionMap.txt"))
            return -1;

        //-----------------------------------------------------------------------------------------------

        // run the main loop
        sf::Clock dtClock;
        float dt = 0.0f;

        while (window.isOpen()){
            dt = dtClock.restart().asSeconds();

            // handle events
            sf::Event event;
            while (window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }   

                //Animating
                player.Shooting(map, window);
                player.PickUp(bags);
                hud.HP_Update(player);

    //            //Mouse position
    //            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    //            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    //            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    //                std::cout<<worldPos.x<<"  "<<worldPos.y<<std::endl;
    //            }

                if(rooms.Room_1ON())
                    rooms.Room_1(map, player, dt);

                if(rooms.Room_2ON())
                    rooms.Room_2(map, player, dt);

                if(rooms.Room_3ON())
                    rooms.Room_3(map, player, dt);

                if(rooms.Room_4ON())
                    rooms.Room_4(map, player, dt);

                if(rooms.Room_5ON())
                    rooms.Room_5(map, player, dt);

                hud.Points(player);

                if(player.initHealth() <= 0){
                    window.close();
                }

                //DRAW
                window.clear();
                window.setView(view);

                //Maps draw
                window.draw(map);
                if(player.spawn_enemies(map, 2) && rooms.enemies_size1() > 0){
                    window.draw(map2);
                }
                if(player.spawn_enemies(map, 2) && rooms.enemies_size2() > 0){
                    window.draw(map2);
                }
                if(player.spawn_enemies(map, 2) && rooms.enemies_size3() > 0){
                    window.draw(map2);
                }
                if(player.spawn_enemies(map, 2) && rooms.enemies_size4() > 0){
                    window.draw(map2);
                }
                if(player.spawn_enemies(map, 2) && rooms.enemies_size5() > 0){
                    window.draw(map2);
                }


                //Player draw
                window.draw(player);
                player.render(window);
                rooms.RenderRoom(window);

                //Bags draw
                for(unsigned int i = 0; i < bags.size(); i++){
                    window.draw(*bags[i]);
                }

                //HUD draw
                window.setView(window.getDefaultView());

                if(MENU_ON == true){
                    hud.RenderMENU(window);
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                            MENU_ON = false;
                        }
                }else{
                    player.Animate(dt, map, view);
                    hud.RenderGUI(window);
                }

                if(rooms.Room_1ON() == false && rooms.Room_2ON() == false && rooms.Room_3ON() == false && rooms.Room_4ON() == false && rooms.Room_5ON() == false){
                    hud.RenderWIN(window);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                        window.close();
                    }
                }

                window.setView(view);
                window.display();

                }


        return 0;
}
