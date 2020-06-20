#ifndef ENEMY_H
#define ENEMY_H

#include <Biblioteki.h>
#include <Character.h>
#include <hero.h>

class Enemy : public character
{
public:
    Enemy(sf::Vector2f positon, sf::Vector2f size, const std::string &path, int health, float enemy_speed, std::string name);

    void render(sf::RenderTarget &target);
    void Move_to_player(const Hero &hero, float &dt);
    void Shooting(Hero &hero, const TileMap &map, float time_s, const sf::Vector2f &size = sf::Vector2f(4.f, 9.f), const std::string &s = "Grafiki/dark_arrow.png");

    void Magic_Attack(Hero &hero, const TileMap &map, float time_s);

    void DamageReceived(int damage);
    int ActualHealth();

public:
    //Arrows
    Arrow black_arrow = Arrow (sf::Vector2f(4.f, 9.f), "Grafiki/dark_arrow.png", 2.f);
    std::vector<std::unique_ptr<Arrow>> black_arrows;

private:    
    int health_;
    float enemy_speed_;
    std::string name_;
    sf::Clock ShootTimer;

    sf::Vector2f PlayerPosition;
    sf::Vector2f EnemyPosition;
    sf::Vector2f Enemy_sub_Player;
    float denominator;
    sf::Vector2f Normalized;


};

#endif // ENEMY_H
