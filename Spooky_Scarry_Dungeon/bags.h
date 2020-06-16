#ifndef BAGS_H
#define BAGS_H

#include <Biblioteki.h>

class Bags : public sf::RectangleShape
{
public:
    Bags(const sf::Vector2f &size = sf::Vector2f(0.f, 0.f), const std::string &path = "brak", const int &val = 1);

    void setPick(const bool &b);
    bool isPicked();

private:
    int value_;
    sf::Texture texture_;

    bool is_picked_ = false;

};

#endif // BAGS_H
