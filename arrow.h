#ifndef ARROW_H
#define ARROW_H

#include<Biblioteki.h>
#include<tilemap.h>


class Arrow : public sf::RectangleShape
{
public:
    Arrow(sf::Vector2f size = sf::Vector2f(5.f, 10.f), const std::string &tex = "C:/Users/szymo/OneDrive/Game_PSiO/SSD/Grafiki/arrow.png", const float &maxSpeed = 10.f);

    void setArrowTexture(const std::string &s, const sf::Vector2f &size);
    void Arrow_Update();

public:
    sf::Vector2f currVelocity;
    std::vector<sf::Vector2f> tiles_;
    float maxSpeed_;

private:  

    float bottom_ar, left_ar, right_ar, top_ar;
    sf::Texture texture_;
};

#endif // ARROW_H
