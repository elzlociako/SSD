#include "bags.h"

Bags::Bags(const sf::Vector2f &size, const std::string &path, const int &val)
{
    setSize(size);
    texture_.loadFromFile(path);
    setTexture(&texture_);

    value_ = val;
}

bool Bags::isPicked()
{
    return is_picked_;
}

void Bags::setPick(const bool &b)
{
    is_picked_ = b;
}
