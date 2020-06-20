#include "animatedsprite.h"

AnimatedSprite::AnimatedSprite()
{

}

void AnimatedSprite::addFrame(const std::string &p)
{  
    frames.emplace_back(p);
}

void AnimatedSprite::Play()
{
    for(unsigned int i = 0; i < frames.size(); i++)
    {
        if(time.getElapsedTime().asSeconds() > 2)
        {
            texture_.loadFromFile(frames[i]);
            setTexture(&texture_);
        }
    }
}
