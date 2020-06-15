#include "hud.h"

HUD::HUD()
{

}

void HUD::HP_Update(Hero &hero)
{
    if(hero.initHealth() < hero.initMaxHealth() && hero.isDamaged() == true){
        width = width - 3*hero.DamageReceived();
        hero.isDam = false;
    }
}

void HUD::HP_Def()
{
    this->HP_background.setSize(sf::Vector2f(300.f, 30.f));
    this->HP_background.setFillColor(sf::Color(25.f, 25.f, 25.f, 200));
    this->HP_background.setPosition(HP.getPosition());

    this->HP.setSize(sf::Vector2f(width, 30.f));
    this->HP.setFillColor(sf::Color::Red);
    this->HP.setPosition(20.f, 20.f);
}

void HUD::RenderGUI(sf::RenderTarget &target)
{
    target.setView(target.getDefaultView());
    target.draw(text);
    target.draw(HP_background);
    target.draw(HP);

}

void HUD::Points(Hero &hero)
{
    std::stringstream stream;
    stream <<"Enemies killed: "<<hero.Points;
    this->text.setString(stream.str());
}

void HUD::initFont()
{
    this->font.loadFromFile("C:/Users/szymo/OneDrive/Game_PSiO/SSD/Font/retro_computer_personal_use.ttf");
}

void HUD::initText()
{
    this->text.setFont(font);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(750.f, 20.f);
}
