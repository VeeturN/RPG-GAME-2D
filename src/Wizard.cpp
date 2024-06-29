
#include <valarray>
#include "SFML/Graphics.hpp"
#include "Wizard.h"
#include "fmt/core.h"

Wizard::Wizard(sf::Texture *texture) {

    row=0;
    wizard.setSize(sf::Vector2f(250, 250));
    wizard.setTexture(texture);
    wizard.setPosition(2980, 70);

    wizardBor.setSize({60,100});
    wizardBor.setFillColor(sf::Color::White);

    wizardHeart.setSize({10,10});
    wizardHeart.setFillColor(sf::Color::White);





    Animation animation(texture);
    Wizard::an=animation;

}

void Wizard::draw(sf::RenderWindow &window,sf::RectangleShape shape2) {
    window.draw(wizard);
    //window.draw(wizardHeart);
    for (int i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[i]);
        bullets[i].move(xpos[i],ypos[i]);

        if (bullets[i].getGlobalBounds().intersects(shape2.getGlobalBounds())) {
            xpos[i]=0;
            ypos[i]=0;
            an.DMG();
            bullets[i].setPosition(-10,-10);
        }
        if (bullets[i].getPosition().x<-25 or bullets[i].getPosition().x>3400 or bullets[i].getPosition().y<-25 or bullets[i].getPosition().y>1602){
            bullets[i].setPosition(-10,-10);
            xpos[i]=0;
            ypos[i]=0;
        }
    }
}

void Wizard::move(sf::Clock &clock1, sf::Clock &clock2,sf::Clock& WizardMultiShoot, sf::RenderWindow &window, sf::RectangleShape PlayerHeart, sf::Texture *texture,sf::Texture *texture2) {
    x= wizardBor.getPosition().x - PlayerHeart.getPosition().x;
    y= wizardBor.getPosition().y - PlayerHeart.getPosition().y;
    bool iddle= true;

    if (WizardHp<=0){
        an.wizardDead(4,clock1);
        wizard.setTextureRect(an.wizardDeaduvRect);
    } else {
        if (an.timer==1 or an.timer==3 or an.timer==5){
            if (x <= 300 and  x>=-300 and y <= 300 and y>=-300 or WizardHp<=29) {
                iddle= false;
                if (wizardBor.getPosition().x > PlayerHeart.getPosition().x) {
                    moveOn.x -= speed;
                    an.wizard(7, clock1);
                    wizard.setTextureRect(an.wizarduvRect);
                }
                if (wizardBor.getPosition().x < PlayerHeart.getPosition().x) {
                    moveOn.x += speed;
                    an.wizard(6, clock1);
                    wizard.setTextureRect(an.wizarduvRect);
                }
                if (wizardBor.getPosition().y > PlayerHeart.getPosition().y) {
                    moveOn.y -= speed;
                    an.wizard(6, clock1);
                    wizard.setTextureRect(an.wizarduvRect);
                }
                if (wizardBor.getPosition().y < PlayerHeart.getPosition().y) {
                    moveOn.y += speed;
                    an.wizard(7, clock1);
                    wizard.setTextureRect(an.wizarduvRect);
                }
                if (wizardBor.getGlobalBounds().intersects(PlayerHeart.getGlobalBounds())) {
                    moveOn = {0, 0};

                    an.wizardIddle(5, clock1);
                    wizard.setTextureRect(an.wizardIddleuvRect);
                }
                wizard.move(moveOn);
                moveOn = {0, 0};
                wizardBor.setPosition(wizard.getPosition().x + 90, wizard.getPosition().y + 80);
                wizardHeart.setPosition(wizard.getPosition().x + 111, wizard.getPosition().y + 126);
            }else if(an.timer>0){
                if (iddle) {
                    an.wizardIddle(5, clock1);
                    wizard.setTextureRect(an.wizardIddleuvRect);
                }
            }
        }else if(an.timer==2 or an.timer==4 or an.timer==6){
            if (wizardBor.getPosition().x > PlayerHeart.getPosition().x) {
                if (an.timer==4){
                    an.wizardAttack(1, clock1);
                    wizard.setTextureRect(an.wizardAttackuvRect);
                    shoot(PlayerHeart,WizardMultiShoot ,texture2);
                } else{
                    an.wizardAttack(3, clock1);
                    wizard.setTextureRect(an.wizardAttackuvRect);
                    oneshoot(PlayerHeart, clock2, texture);
                }
            }
            if (wizardBor.getPosition().x <= PlayerHeart.getPosition().x) {
                if (an.timer==4){
                    an.wizardAttack(0, clock1);
                    wizard.setTextureRect(an.wizardAttackuvRect);
                    shoot(PlayerHeart,WizardMultiShoot, texture2);
                } else{
                    an.wizardAttack(2, clock1);
                    wizard.setTextureRect(an.wizardAttackuvRect);
                    oneshoot(PlayerHeart, clock2, texture);
                }
            }
        } else if(an.timer>0) {
            if (moveOn.x == 0 and moveOn.y == 0) {
                an.wizardIddle(5, clock1);
                wizard.setTextureRect(an.wizardIddleuvRect);
            }
        }
    }
}

void Wizard::shoot(sf::RectangleShape shape2,sf::Clock &WizardMultiShoot,sf::Texture *texture) {
    if (WizardMultiShoot.getElapsedTime().asMilliseconds() >= 400) {
        bullets.push_back(sf::CircleShape());
        bullets.back().setTexture(texture);
        bullets.back().setRadius(30);
        bullets.back().setOrigin(0, 0); //-40, -65
        bullets.back().setPosition(wizardBor.getPosition().x + 40, wizardBor.getPosition().y + 65);

        int x;
        int y;
        x = 5 * cos(atan2(shape2.getPosition().y - wizardHeart.getPosition().y,
                          shape2.getPosition().x - wizardHeart.getPosition().x));
        y = 5 * sin(atan2(shape2.getPosition().y - wizardHeart.getPosition().y,
                          shape2.getPosition().x - wizardHeart.getPosition().x));
        xpos.push_back(x);
        ypos.push_back(y);
        WizardMultiShoot.restart();
    }
}
void Wizard::oneshoot(sf::RectangleShape shape2,sf::Clock &OneShoot,sf::Texture *texture2) {
    if (OneShoot.getElapsedTime().asMilliseconds() >= 1000) {
        bullets.push_back(sf::CircleShape());
        bullets.back().setTexture(texture2);
        bullets.back().setRadius(10);
        bullets.back().setOrigin(0,0); //-40, -65
        bullets.back().setPosition(wizardBor.getPosition().x+40,wizardBor.getPosition().y+65);

        int x;
        int y;
        x = 5 * cos(atan2(shape2.getPosition().y - wizardHeart.getPosition().y,
                          shape2.getPosition().x - wizardHeart.getPosition().x));
        y = 5 * sin(atan2(shape2.getPosition().y - wizardHeart.getPosition().y,
                          shape2.getPosition().x - wizardHeart.getPosition().x));
        xpos.push_back(x);
        ypos.push_back(y);
        OneShoot.restart();
    }
}
