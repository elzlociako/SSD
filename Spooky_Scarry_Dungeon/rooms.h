#ifndef FIGHT_H
#define FIGHT_H

#include <Biblioteki.h>
#include <enemy.h>
#include <player.h>
#include <arrow.h>
#include <hud.h>

class Rooms
{
public:
    Rooms();

    void Room_1(TileMap &map, Hero &player, float &dt, HUD &hud);
    void Room_2(TileMap &map, Hero &player, float &dt, HUD &hud);
    void Room_3(TileMap &map, Hero &player, float &dt, HUD &hud);
    void Room_4(TileMap &map, Hero &player, float &dt, HUD &hud);
    void Room_5(TileMap &map, Hero &player, float &dt, HUD &hud);

    int enemies_size1();
    int enemies_size2();
    int enemies_size3();
    int enemies_size4();
    int enemies_size5();

    bool Room_1ON();
    bool Room_2ON();
    bool Room_3ON();
    bool Room_4ON();
    bool Room_5ON();

    void RenderRoom(sf::RenderTarget &target);

private:
    std::vector<std::unique_ptr<Enemy>> enemies1;
    std::vector<std::unique_ptr<Enemy>> enemies2;
    std::vector<std::unique_ptr<Enemy>> enemies3;
    std::vector<std::unique_ptr<Enemy>> enemies4;
    std::vector<std::unique_ptr<Enemy>> enemies5;

    bool SpawnEnemies1 = true;
    bool SpawnEnemies2 = false;
    bool SpawnEnemies3 = false;
    bool SpawnEnemies4 = false;
    bool SpawnEnemies5 = false;


};

#endif // FIGHT_H
