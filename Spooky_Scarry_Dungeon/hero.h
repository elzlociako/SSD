#ifndef HERO_H
#define HERO_H

#include<Biblioteki.h>
#include<Character.h>
#include <bags.h>

class Hero : public character
{
public:
    Hero(sf::Vector2f positon, sf::Vector2f size, const std::string &path);

    void Shooting(const TileMap &map, sf::RenderWindow &w);
    void render(sf::RenderTarget &target);

    int DamageReceived();

    int initMaxHealth();
    int initHealth();

    void Damaged(int dam);
    bool isDamaged();

    void PickUp(std::vector<std::unique_ptr<Bags>> &bags);

    bool isDam = false;

public:
    //Arrows
    Arrow arrow = Arrow(sf::Vector2f(4.f, 9.f),"C:/Users/szymo/OneDrive/Game_PSiO/SSD/Grafiki/arrow.png", 10.f);
    std::vector<std::unique_ptr<Arrow>> arrows_;

    int Points = 0;

private:

    //Health
    int MaxHealth = 100;
    int Health = MaxHealth;
    int Damage = 0;


    sf::Clock ShootTimer;
    sf::Vector2f mousePosWindow_;
    sf::Vector2f aimDir_;
    sf::Vector2f aimDirNorm_;
    sf::Vector2f playerCenter_;

    sf::Clock hit_time;

};


#endif // HERO_H
