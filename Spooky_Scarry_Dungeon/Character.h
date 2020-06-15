#ifndef PLAYER_H
#define PLAYER_H

#include <Biblioteki.h>
#include "tilemap.h"
#include <arrow.h>

class character : public sf::RectangleShape
{
public:
    character(sf::Vector2f positon = sf::Vector2f(0.f, 0.f) , sf::Vector2f size = sf::Vector2f(16.f, 16.f) , sf::Color color = sf::Color::White);

    virtual void Animate(float &dt, const TileMap &map, sf::View &v);
    bool spawn_enemies(const TileMap &map, const int &num);

public:
    std::vector<sf::Vector2f> tiles;

protected:
   void Update();


protected:
    float PI = 3.14159265f;
    float bottom, left, right, top;
    float speed_ = 100;

    sf::Texture texture_;

};

#endif // PLAYER_H
