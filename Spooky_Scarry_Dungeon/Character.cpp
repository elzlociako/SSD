#include "Character.h"

character::character(sf::Vector2f positon, sf::Vector2f size, sf::Color color)
{
    this->setPosition(positon);
    this->setSize(size);
    this->setFillColor(color);
}

void character::Update()
{

    bottom = getPosition().y + getSize().y;
    top = getPosition().y + 15;
    left = getPosition().x + 8;
    right = getPosition().x + getSize().x - 8;

    sf::Vector2f TopLeft(sf::Vector2i((int)left/16, (int)top/16));
    sf::Vector2f TopRight(sf::Vector2i((int)right/16, (int)top/16));
    sf::Vector2f BottomLeft(sf::Vector2i((int)left/16, (int)bottom/16));
    sf::Vector2f BottomRight(sf::Vector2i((int)right/16, (int)bottom/16));

    tiles.clear();

    tiles.emplace_back(TopLeft);
    if(std::find(tiles.begin(), tiles.end(), TopRight) == tiles.end()) {
        tiles.emplace_back(TopRight);
    }
    if(std::find(tiles.begin(), tiles.end(), BottomLeft) == tiles.end()) {
        tiles.emplace_back(BottomLeft);
    }
    if(std::find(tiles.begin(), tiles.end(), BottomRight) == tiles.end()) {
        tiles.emplace_back(BottomRight);
    }

}


void character::Animate(float &dt, const TileMap &map, sf::View &v)
{
    sf::Vector2f speed(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        speed.x = this->speed_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        speed.x = -this->speed_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        speed.y = -this->speed_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        speed.y = this->speed_;

    move(speed * dt);
    v.move(speed * dt);

    Update();

    sf::Vector2f col_speed(0.f, 0.f);

    for(unsigned int i = 0; i<tiles.size(); i++){
        if(map.cmap[tiles[i].y][tiles[i].x] == 1) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                col_speed.x = -this->speed_;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                col_speed.x = this->speed_;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                col_speed.y = this->speed_;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                col_speed.y = -this->speed_;

            move(col_speed * dt);
            v.move(col_speed * dt);
            break;
        }
    }
}


bool character::spawn_enemies(const TileMap &map, const int &num)
{
    for(unsigned int i = 0; i<tiles.size(); i++)
        if(map.cmap[tiles[i].y][tiles[i].x] == num) {
            return true;
        }
    return false;
}




