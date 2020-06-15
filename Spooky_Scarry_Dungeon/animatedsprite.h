#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <Biblioteki.h>

class AnimatedSprite : public sf::RectangleShape
{
public:
    AnimatedSprite();

    void addFrame(const std::string &p);
    void Play();

protected:
    std::vector<std::string> frames;
    sf::Clock time;
    sf::Texture texture_;
};

#endif // ANIMATEDSPRITE_H
