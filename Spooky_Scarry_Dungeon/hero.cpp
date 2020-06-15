#include "hero.h"


Hero::Hero(sf::Vector2f positon, sf::Vector2f size, const std::string &path)
{
    this->setPosition(positon);
    this->setSize(size);
    texture_.loadFromFile(path);
    setTexture(&texture_);
}

void Hero::Shooting(const TileMap &map, sf::RenderWindow &w)
{
    playerCenter_ = sf::Vector2f((getPosition().x + getPosition().x + 24 )/ 2, (getPosition().y + getPosition().y + 24 )/ 2);
    mousePosWindow_ = sf::Vector2f(w.mapPixelToCoords(sf::Mouse::getPosition(w)));
    aimDir_ = mousePosWindow_ - playerCenter_;
    aimDirNorm_ = aimDir_ / sqrt(pow(aimDir_.x, 2.f) + pow(aimDir_.y, 2.f));

    float deg = atan2(aimDirNorm_.y, aimDirNorm_.x) * 180 / PI;
    arrow.setRotation(deg + 90);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ShootTimer.getElapsedTime().asSeconds() > 1.f)
    {
        arrow.setPosition(playerCenter_);
        arrow.currVelocity = aimDirNorm_ * arrow.maxSpeed_;
        arrows_.push_back(std::make_unique<Arrow>(arrow));
        ShootTimer.restart();
    }

    for (size_t i = 0; i < arrows_.size(); i++)
    {
        arrows_[i]->Arrow_Update();
        arrows_[i]->move(arrows_[i]->currVelocity);

        //Out of bounds
        for(size_t j = 0; j<arrows_[i]->tiles_.size(); j++){
            if(map.cmap[arrows_[i]->tiles_[j].y][arrows_[i]->tiles_[j].x] == 1) {
                arrows_.erase(arrows_.begin() + i);
                break;
            }
        }
    }
}


void Hero::render(sf::RenderTarget &target)
{
    for (size_t i = 0; i < arrows_.size(); i++)
        target.draw(*arrows_[i]);
}

int Hero::initMaxHealth()
{
    return MaxHealth;
}

int Hero::initHealth()
{
    return Health;
}

bool Hero::isDamaged()
{
    return isDam;
}

void Hero::Damaged(int dam)
{
        Damage = dam;
        Health -= Damage;
        hit_time.restart();
}

int Hero::DamageReceived()
{
    return Damage;
}

void Hero::PickUp(std::vector<std::unique_ptr<Bags>> &bags)
{
    for(unsigned int i = 0; i < bags.size(); i++)
    {
        if(getGlobalBounds().intersects(bags[i]->getGlobalBounds()))
        {
            bags[i]->setPick(true);
            bags.erase(bags.begin() + i);
        }
    }
}
