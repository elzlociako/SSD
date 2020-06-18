#include "rooms.h"


Rooms::Rooms()
{
    hitSoundBuf.loadFromFile("Muzyka/EnemyHit.wav");
    hitSound.setBuffer(hitSoundBuf);
    hitSound.setVolume(50.f);

    hitPlayerSoundBuf.loadFromFile("Muzyka/PlayerHit.wav");
    hitPlayerSound.setBuffer(hitPlayerSoundBuf);
}

void Rooms::Room_1(TileMap &map, Hero &player, float &dt)
{
       if(player.spawn_enemies(map, 22) && enemies1.size() < 5){
            auto enemy = std::make_unique<Enemy>(sf::Vector2f(rand() % 100 + 20, rand() % 150 + 700), sf::Vector2f(14.f, 18.f), "Grafiki/Characters/Knight/k1.png", 100, rand() % 9 + 1, "Knight");
            enemies1.emplace_back(std::move(enemy));
        }

    for(unsigned int i = 0; i< enemies1.size(); i++)
    {
        enemies1[i]->Move_to_player(player, dt);
        enemies1[i]->Shooting(player, map, rand() % 1 + 2);

        if(player.isDamaged()){
            hitPlayerSound.play();
            player.Damaged(rand() % 5 + 10);
            player.isDam = false;;
        }

        for(unsigned int j = 0; j < player.arrows_.size(); j++){
            if(player.arrows_[j]->getGlobalBounds().intersects(enemies1[i]->getGlobalBounds()))
            {
                hitSound.play();
                player.arrows_.erase(player.arrows_.begin() + j);
                    enemies1[i]->DamageReceived(30 + rand() % 50);
                        if(enemies1[i]->ActualHealth() <= 0)
                        {
                            enemies1.erase(enemies1.begin() + i);
                            player.Points++;
                        }
                                if(enemies1.size() == 0){
                                    SpawnEnemies1 = false;
                                    SpawnEnemies2 = true;
                                }
                break;
            }
        }
    }
}

void Rooms::Room_2(TileMap &map, Hero &player, float &dt)
{
       if(player.spawn_enemies(map, 33) && enemies2.size() < 7){
            auto enemy = std::make_unique<Enemy>(sf::Vector2f(rand() % 180 + 420, rand() % 165 + 695), sf::Vector2f(14.f, 18.f), "Grafiki/Characters/Knight/k1.png", 100, rand() % 9 + 1, "Knight");
            enemies2.emplace_back(std::move(enemy));
        }

    for(unsigned int i = 0; i< enemies2.size(); i++)
    {
        enemies2[i]->Move_to_player(player, dt);
        enemies2[i]->Shooting(player, map, rand() % 1 + 2);
        if(player.isDamaged()){
            hitPlayerSound.play();
            player.Damaged(rand() % 5 + 10);
            player.isDam = false;
        }

        for(unsigned int j = 0; j < player.arrows_.size(); j++){
            if(player.arrows_[j]->getGlobalBounds().intersects(enemies2[i]->getGlobalBounds()))
            {
                hitSound.play();
                player.arrows_.erase(player.arrows_.begin() + j);
                    enemies2[i]->DamageReceived(30 + rand() % 50);
                        if(enemies2[i]->ActualHealth() <= 0)
                        {
                            enemies2.erase(enemies2.begin() + i);
                            player.Points++;
                        }
                                if(enemies2.size() == 0){
                                    SpawnEnemies2 = false;
                                    SpawnEnemies3 = true;
                                }
                break;
            }
        }
    }
}

void Rooms::Room_3(TileMap &map, Hero &player, float &dt)
{
       if(player.spawn_enemies(map, 44) && enemies3.size() < 5){
            auto enemy = std::make_unique<Enemy>(sf::Vector2f(rand() % 180 + 420, rand() % 170 + 385), sf::Vector2f(12.f, 18.f), "Grafiki/Characters/Knight/k2.png", 130, rand() % 9 + 1, "EliteKnight");
            enemies3.emplace_back(std::move(enemy));
        }

    for(unsigned int i = 0; i< enemies3.size(); i++)
    {
        enemies3[i]->Move_to_player(player, dt);
        enemies3[i]->Shooting(player, map, rand() % 1 + 2);
        if(player.isDamaged()){
            hitPlayerSound.play();
            player.Damaged(rand() % 5 + 10);
            player.isDam = false;
        }

        for(unsigned int j = 0; j < player.arrows_.size(); j++){
            if(player.arrows_[j]->getGlobalBounds().intersects(enemies3[i]->getGlobalBounds()))
            {
                hitSound.play();
                player.arrows_.erase(player.arrows_.begin() + j);
                    enemies3[i]->DamageReceived(30 + rand() % 50);
                        if(enemies3[i]->ActualHealth() <= 0)
                        {
                            enemies3.erase(enemies3.begin() + i);
                            player.Points++;
                        }
                                if(enemies3.size() == 0){
                                    SpawnEnemies3 = false;
                                    SpawnEnemies4 = true;
                                }
                break;
            }
        }
    }
}

void Rooms::Room_4(TileMap &map, Hero &player, float &dt)
{
       if(player.spawn_enemies(map, 55) && enemies4.size() < 7){
            auto enemy = std::make_unique<Enemy>(sf::Vector2f(rand() % 185 + 420, rand() % 170 + 35), sf::Vector2f(12.f, 20.f), "Grafiki/Characters/Knight/k2.png", 150, rand() % 9 + 1, "EliteKnight");
            enemies4.emplace_back(std::move(enemy));
        }

    for(unsigned int i = 0; i< enemies4.size(); i++)
    {
        enemies4[i]->Move_to_player(player, dt);
        enemies4[i]->Shooting(player, map, rand() % 1 + 2);
        if(player.isDamaged()){
            hitPlayerSound.play();
            player.Damaged(rand() % 5 + 10);
            player.isDam = false;
        }

        for(unsigned int j = 0; j < player.arrows_.size(); j++){
            if(player.arrows_[j]->getGlobalBounds().intersects(enemies4[i]->getGlobalBounds()))
            {
                hitSound.play();
                player.arrows_.erase(player.arrows_.begin() + j);
                    enemies4[i]->DamageReceived(30 + rand() % 50);
                        if(enemies4[i]->ActualHealth() <= 0)
                        {
                            enemies4.erase(enemies4.begin() + i);
                            player.Points++;
                        }
                                if(enemies4.size() == 0){
                                    SpawnEnemies4 = false;
                                    SpawnEnemies5 = true;
                                }
                break;
            }
        }
    }
}

void Rooms::Room_5(TileMap &map, Hero &player, float &dt)
{
       if(player.spawn_enemies(map, 66) && enemies5.size() < 2){
            auto enemy = std::make_unique<Enemy>(sf::Vector2f(rand() % 180 + 785, rand() % 170 + 690), sf::Vector2f(32.f, 32.f), "Grafiki/Characters/Knight/LK1.png", 450, rand() % 20, "Boss");
            enemies5.emplace_back(std::move(enemy));
        }

    for(unsigned int i = 0; i< enemies5.size(); i++)
    {
        enemies5[i]->Move_to_player(player, dt);
        enemies5[i]->Shooting(player, map, rand() % 1 + 2, sf::Vector2f(9.f, 9.f), "Grafiki/boss_mag.png");
        if(player.isDamaged()){
            hitPlayerSound.play();
            player.Damaged(rand() % 20 + 15);
            player.isDam = false;
        }

        for(unsigned int j = 0; j < player.arrows_.size(); j++){
            if(player.arrows_[j]->getGlobalBounds().intersects(enemies5[i]->getGlobalBounds()))
            {
                hitSound.play();
                player.arrows_.erase(player.arrows_.begin() + j);
                    enemies5[i]->DamageReceived(30 + rand() % 50);
                        if(enemies5[i]->ActualHealth() <= 0)
                        {
                            enemies5.erase(enemies5.begin() + i);
                            player.Points++;
                        }
                                if(enemies5.size() == 0){
                                    SpawnEnemies5 = false;
                                }
                break;
            }
        }
    }
}

void Rooms::RenderRoom(sf::RenderTarget &target)
{
    for(unsigned int i = 0; i< enemies1.size(); i++){
        target.draw(*enemies1[i]);
        enemies1[i]->render(target);
    }

    for(unsigned int i = 0; i< enemies2.size(); i++){
        target.draw(*enemies2[i]);
        enemies2[i]->render(target);
    }

    for(unsigned int i = 0; i< enemies3.size(); i++){
        target.draw(*enemies3[i]);
        enemies3[i]->render(target);
    }

    for(unsigned int i = 0; i< enemies4.size(); i++){
        target.draw(*enemies4[i]);
        enemies4[i]->render(target);
    }

    for(unsigned int i = 0; i< enemies5.size(); i++){
        target.draw(*enemies5[i]);
        enemies5[i]->render(target);
    }
}

int Rooms::enemies_size1()
{
    return enemies1.size();
}

int Rooms::enemies_size2()
{
    return enemies2.size();
}

int Rooms::enemies_size3()
{
    return enemies3.size();
}

int Rooms::enemies_size4()
{
    return enemies4.size();
}

int Rooms::enemies_size5()
{
    return enemies5.size();
}

bool Rooms::Room_1ON(){
    return SpawnEnemies1;
}

bool Rooms::Room_2ON(){
    return SpawnEnemies2;
}

bool Rooms::Room_3ON(){
    return SpawnEnemies3;
}

bool Rooms::Room_4ON(){
    return SpawnEnemies4;
}

bool Rooms::Room_5ON(){
    return SpawnEnemies5;
}
