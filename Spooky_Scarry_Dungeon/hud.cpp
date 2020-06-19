#include "hud.h"

HUD::HUD() {}

void HUD::HP_Update(Hero &hero)
{
    this->HP_background.setSize(sf::Vector2f(300.f, 30.f));
    this->HP_background.setFillColor(sf::Color(25.f, 25.f, 25.f, 200));
    this->HP_background.setPosition(HP.getPosition());

    this->HP.setSize(sf::Vector2f(3*hero.initHealth(), 30.f));
    this->HP.setFillColor(sf::Color::Red);
    this->HP.setPosition(20.f, 20.f);
}

void HUD::RenderGUI(sf::RenderTarget &target)
{
    target.draw(textE);
    target.draw(HP_background);
    target.draw(HP);
}

void HUD::RenderWIN(sf::RenderTarget &target)
{
    target.draw(Win_text);
    target.draw(Win_text2);
}

void HUD::RenderMENU(sf::RenderTarget &target)
{
    target.draw(MenuText1);
    target.draw(MenuText2);
    target.draw(MenuText3);

}

void HUD::Points(Hero &hero)
{
    std::stringstream stream;
    stream <<"Enemies killed: "<<hero.Points;
    this->textE.setString(stream.str());
}

void HUD::initFont()
{
    this->font.loadFromFile("Font/retro_computer_personal_use.ttf");
}

void HUD::initText()
{
    this->textE.setFont(font);
    this->textE.setFillColor(sf::Color::White);
    this->textE.setCharacterSize(20);
    this->textE.setPosition(740.f, 20.f);
}

void HUD::initWinText()
{
    Win_text.setFont(font);
    Win_text.setFillColor(sf::Color::Red);
    Win_text.setCharacterSize(150);
    Win_text.setPosition(103, 300);
    Win_text.setString("YOU WIN!");

    Win_text2.setFont(font);
    Win_text2.setFillColor(sf::Color::White);
    Win_text2.setCharacterSize(30);
    Win_text2.setPosition(285, 500);
    Win_text2.setString("Press ESCAPE to exit");

}

void HUD::initMENU()
{
    MenuText1.setFont(font);
    MenuText3.setFont(font);
    MenuText1.setFillColor(sf::Color::Red);
    MenuText3.setFillColor(sf::Color::Red);
    MenuText1.setCharacterSize(70);
    MenuText3.setCharacterSize(100);
    MenuText1.setPosition(150, 40);
    MenuText3.setPosition(215, 160);
    MenuText1.setString("SPOOKY, SCARRY");
    MenuText3.setString("DUNGEON");

    MenuText2.setFont(font);
    MenuText2.setFillColor(sf::Color::White);
    MenuText2.setCharacterSize(55);
    MenuText2.setPosition(120, 670);
    MenuText2.setString("Press ENTER to play");


}
