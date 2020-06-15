#include "arrow.h"

Arrow::Arrow(sf::Vector2f size, const std::string &tex, const float &maxSpeed)
        : currVelocity(0.f, 0.f), maxSpeed_(maxSpeed)
    {
        setSize(size);
        texture_.loadFromFile(tex);
        setTexture(&texture_);

    }

void Arrow::Arrow_Update()
{
    bottom_ar = getPosition().y + getSize().y;
    top_ar = getPosition().y;
    left_ar = getPosition().x;
    right_ar = getPosition().x + getSize().x;

    sf::Vector2f TopLeft(sf::Vector2i((int)left_ar/16, (int)top_ar/16));
    sf::Vector2f TopRight(sf::Vector2i((int)right_ar/16, (int)top_ar/16));
    sf::Vector2f BottomLeft(sf::Vector2i((int)left_ar/16, (int)bottom_ar/16));
    sf::Vector2f BottomRight(sf::Vector2i((int)right_ar/16, (int)bottom_ar/16));

    tiles_.clear();

    tiles_.emplace_back(TopLeft);
    if(std::find(tiles_.begin(), tiles_.end(), TopRight) == tiles_.end()) {
        tiles_.emplace_back(TopRight);
    }
    if(std::find(tiles_.begin(), tiles_.end(), BottomLeft) == tiles_.end()) {
        tiles_.emplace_back(BottomLeft);
    }
    if(std::find(tiles_.begin(), tiles_.end(), BottomRight) == tiles_.end()) {
        tiles_.emplace_back(BottomRight);
    }
}

void Arrow::setArrowTexture(const std::string &s, const sf::Vector2f &size)
{
    texture_.loadFromFile(s);
    setTexture(&texture_);
    setSize(size);
}

//void Arrow::Shooting(const Hero &hero, const sf::RenderWindow &w, const TileMap &map)
//{
//    playerCenter_ = sf::Vector2f(hero.getPosition().x + 8 , hero.getPosition().y + 16);
//    mousePosWindow_ = sf::Vector2f(w.mapPixelToCoords(sf::Mouse::getPosition(w)));
//    aimDir_ = mousePosWindow_ - playerCenter_;
//    aimDirNorm_ = aimDir_ / sqrt(pow(aimDir_.x, 2.f) + pow(aimDir_.y, 2.f));

//    float PI = 3.14159265f;
//    float deg = atan2(aimDirNorm_.y, aimDirNorm_.x) * 180 / PI;
//    setRotation(deg + 90);

//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ShootTimer.getElapsedTime().asSeconds() > 1.f)
//    {
//        setPosition(playerCenter_);
//        currVelocity = aimDirNorm_ * maxSpeed_;
//        arrows_.emplace_back(std::make_unique<Arrow>(Arrow()));
//        ShootTimer.restart();
//    }

//    for (size_t i = 0; i < arrows_.size(); i++)
//    {
//        arrows_[i]->Arrow_Update();
//        arrows_[i]->move(arrows_[i]->currVelocity);

//        //Out of bounds
//        for(size_t j = 0; j<arrows_[i]->tiles_.size(); j++){
//            if(map.cmap[arrows_[i]->tiles_[j].y][arrows_[i]->tiles_[j].x] == 1) {
//                arrows_.erase(arrows_.begin() + i);
//                break;
//            }
//        }
//    }
//}

//void Arrow::draw(sf::RenderTarget &target)
//{
//    for(size_t i = 0; i < arrows_.size(); i++)
//        target.draw(*arrows_[i]);
//}
