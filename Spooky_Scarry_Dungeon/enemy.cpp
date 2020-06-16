#include "enemy.h"

Enemy::Enemy(sf::Vector2f positon, sf::Vector2f size, const std::string &path, int health, float enemy_speed, std::string name) :
    health_(health), enemy_speed_(enemy_speed), name_(name)
{
    this->setPosition(positon);
    this->setSize(size);
    texture_.loadFromFile(path);
    setTexture(&texture_);
}

void Enemy::Move_to_player(const Hero &hero, float &dt)
{
    PlayerPosition = sf::Vector2f(hero.getPosition().x, hero.getPosition().y);
    EnemyPosition = sf::Vector2f(getPosition().x, getPosition().y);
    Enemy_sub_Player = PlayerPosition - EnemyPosition;
    denominator = sqrt(pow(Enemy_sub_Player.x, 2.f) + pow(Enemy_sub_Player.y, 2.f));
    Normalized = Enemy_sub_Player / denominator;

    sf::Vector2f VectorToPosition(Enemy_sub_Player.x / denominator, Enemy_sub_Player.y / denominator);
    move(VectorToPosition  * enemy_speed_ * dt);

    if(getGlobalBounds().intersects(hero.getGlobalBounds()))
        move(VectorToPosition * -enemy_speed_ * dt);
}

void Enemy::Shooting(Hero &hero, const TileMap &map, float time_s, const sf::Vector2f &size, const std::string &s)
{

    black_arrow.setArrowTexture(s, size);
    float deg = atan2(Enemy_sub_Player.y, Enemy_sub_Player.x) * 180 / PI;
    black_arrow.setRotation(deg + 90);

    if (ShootTimer.getElapsedTime().asSeconds() > time_s)
    {
        black_arrow.setPosition(sf::Vector2f((getPosition().x + getPosition().x + 24 )/ 2, (getPosition().y + getPosition().y + 24 )/ 2));
        black_arrow.currVelocity = Normalized * black_arrow.maxSpeed_;
        black_arrows.push_back(std::make_unique<Arrow>(black_arrow));
        ShootTimer.restart();
    }

    for (size_t i = 0; i < black_arrows.size(); i++)
    {
        black_arrows[i]->Arrow_Update();
        black_arrows[i]->move(black_arrows[i]->currVelocity);
        if(black_arrows[i]->getGlobalBounds().intersects(hero.getGlobalBounds())){
            black_arrows.erase(black_arrows.begin() + i);
               hero.isDam = true;
               break;
        }

        //Out of bounds
        for(size_t j = 0; j<black_arrows[i]->tiles_.size(); j++){
            if(map.cmap[black_arrows[i]->tiles_[j].y][black_arrows[i]->tiles_[j].x] == 1) {
                black_arrows.erase(black_arrows.begin() + i);
                break;
            }
        }
    }
}

void Enemy::render(sf::RenderTarget &target)
{
    for (size_t i = 0; i < black_arrows.size(); i++)
        target.draw(*black_arrows[i]);
}

void Enemy::DamageReceived(int damage)
{
    health_ = health_ - damage;
}

int Enemy::ActualHealth(){
    return health_;
}

void Enemy::Magic_Attack(Hero &hero, const TileMap &map, float time_s)
{
    hero.isDam = false;
    float deg = atan2(Enemy_sub_Player.y, Enemy_sub_Player.x) * 180 / PI;
    black_arrow.setRotation(deg + 90);

    if (ShootTimer.getElapsedTime().asSeconds() > time_s)
    {
        black_arrow.setPosition(sf::Vector2f((getPosition().x + getPosition().x + getSize().x)/ 2, (getPosition().y + getPosition().y + getSize().y)/ 2));
        black_arrow.currVelocity = Normalized * black_arrow.maxSpeed_;
        black_arrows.push_back(std::make_unique<Arrow>(black_arrow));
        ShootTimer.restart();
    }


    for (size_t i = 0; i < black_arrows.size(); i++)
    {
        black_arrows[i]->Arrow_Update();
        black_arrows[i]->move(black_arrows[i]->currVelocity);

        if(black_arrows[i]->getGlobalBounds().intersects(hero.getGlobalBounds())){
            black_arrows.erase(black_arrows.begin() + i);
               hero.isDam = true;
            break;
        }

        //Out of bounds
        for(size_t j = 0; j<black_arrows[i]->tiles_.size(); j++){
            if(map.cmap[black_arrows[i]->tiles_[j].y][black_arrows[i]->tiles_[j].x] == 1) {
                black_arrows.erase(black_arrows.begin() + i);
                break;
            }
        }
    }
}
