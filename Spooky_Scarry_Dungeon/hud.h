#ifndef HUD_H
#define HUD_H

#include <Biblioteki.h>
#include <bags.h>
#include <hero.h>

class HUD
{
public:
    HUD();

    void HP_Update(Hero &hero);
    void RenderGUI(sf::RenderTarget &target);

    void Points(Hero &hero);
    void initFont();
    void initText();

private:
    sf::RectangleShape HP;
    sf::RectangleShape HP_background;

    float width = 300.f;

    sf::Font font;
    sf::Text textE;
    sf::Text textW;

};

#endif // HUD_H
