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
