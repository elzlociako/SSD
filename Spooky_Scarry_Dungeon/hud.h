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
    void RenderWIN(sf::RenderTarget &target);
    void RenderMENU(sf::RenderTarget &target);

    void Points(Hero &hero);
    void initFont();
    void initText();

    void initWinText();
    void initMENU();

    bool bo = true;

private:
    sf::RectangleShape HP;
    sf::RectangleShape HP_background;;

    sf::Font font;
    sf::Text textE;
    sf::Text Win_text;
    sf::Text Win_text2;
    sf::Text MenuText1;
    sf::Text MenuText2;
    sf::Text MenuText3;

};

#endif // HUD_H
