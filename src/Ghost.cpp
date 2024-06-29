//
// Created by dawid on 14.05.2024.
//
#include <valarray>
#include "SFML/Graphics.hpp"
#include "Ghost.h"
#include "fmt/core.h"

Ghost::Ghost(sf::Texture *texture) {

    row=0;
    ghost.setSize(sf::Vector2f(150, 150));
    ghost.setTexture(texture);
    ghost.setPosition(765, 205);

    ghostBor.setSize({80,120});
    ghostBor.setFillColor(sf::Color::White);

    ghostHeart.setSize({10,10});
    ghostHeart.setFillColor(sf::Color::White);





    Animation animation(texture);
    Ghost::an=animation;

}

void Ghost::draw(sf::RenderWindow &window,sf::RectangleShape shape2) {
    window.draw(ghost);
    //window.draw(ghostBor);
    //window.draw(ghostHeart);
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

void Ghost::move(sf::Clock &clock1, sf::Clock &clock2, sf::RenderWindow &window, sf::RectangleShape& PlayerHeart, sf::Texture *texture) {
    x= ghostBor.getPosition().x - PlayerHeart.getPosition().x;
    y= ghostBor.getPosition().y - PlayerHeart.getPosition().y;
    bool iddle= true;

    if (GhostHp<=0){
        an.ghostDead(1,clock1);
        ghost.setTextureRect(an.uvRect9);
    } else {
        if (an.timer==1 or an.timer==3 or an.timer==5){
        if (x <= 300 and  x>=-300 and y <= 300 and y>=-300 or GhostHp<=24) {
            iddle= false;
            if (ghostBor.getPosition().x > PlayerHeart.getPosition().x) {
                moveOn.x -= speed;
                an.ghost(2, clock1);
                ghost.setTextureRect(an.uvRect7);
            }
            if (ghostBor.getPosition().x < PlayerHeart.getPosition().x) {
                moveOn.x += speed;
                an.ghost(3, clock1);
                ghost.setTextureRect(an.uvRect7);
            }
            if (ghostBor.getPosition().y > PlayerHeart.getPosition().y) {
                moveOn.y -= speed;
                an.ghost(0, clock1);
                ghost.setTextureRect(an.uvRect7);
            }
            if (ghostBor.getPosition().y < PlayerHeart.getPosition().y) {
                moveOn.y += speed;
                an.ghost(0, clock1);
                ghost.setTextureRect(an.uvRect7);
            }
            if (ghostBor.getGlobalBounds().intersects(PlayerHeart.getGlobalBounds())) {
                moveOn = {0, 0};

                an.ghost(2, clock1);
                ghost.setTextureRect(an.uvRect7);
            }
            ghost.move(moveOn);
            moveOn = {0, 0};
            ghostBor.setPosition(ghost.getPosition().x + 20, ghost.getPosition().y + 20);
            ghostHeart.setPosition(ghost.getPosition().x + 70, ghost.getPosition().y + 70);
        }else if(an.timer>0){
            if (iddle) {
                an.ghostIddle(0, clock1);
                ghost.setTextureRect(an.uvRect8);
            }
        }
        }else if(an.timer==2 or an.timer==4 or an.timer==6){
            if (ghostBor.getPosition().x > PlayerHeart.getPosition().x) {
                an.ghostAttack(5, clock1);
                ghost.setTextureRect(an.uvRect10);
                if (an.timer==4){
                    shoot(PlayerHeart, texture);
                } else{
                    oneshoot(PlayerHeart, clock2, texture);
                }
            }
            if (ghostBor.getPosition().x <= PlayerHeart.getPosition().x) {
                an.ghostAttack(4, clock1);
                ghost.setTextureRect(an.uvRect10);
                if (an.timer==4){
                    shoot(PlayerHeart, texture);
                } else{
                    oneshoot(PlayerHeart, clock2, texture);
                }
            }
        } else if(an.timer>0) {
            if (moveOn.x == 0 and moveOn.y == 0) {
                an.ghostIddle(0, clock1);
                ghost.setTextureRect(an.uvRect8);
            }
        }
    }
}

void Ghost::shoot(sf::RectangleShape shape2,sf::Texture *texture) {
    bullets.push_back(sf::CircleShape());
    bullets.back().setTexture(texture);
    bullets.back().setRadius(10);
    bullets.back().setOrigin(0,0); //-40, -65
    bullets.back().setPosition(ghostBor.getPosition().x+40,ghostBor.getPosition().y+65);

    int x;
    int y;
            x=5 * cos(atan2(shape2.getPosition().y-ghostHeart.getPosition().y,
                            shape2.getPosition().x-ghostHeart.getPosition().x));
            y=5 * sin(atan2(shape2.getPosition().y-ghostHeart.getPosition().y,
                            shape2.getPosition().x-ghostHeart.getPosition().x));
            xpos.push_back(x);
            ypos.push_back(y);
}
void Ghost::oneshoot(sf::RectangleShape shape2,sf::Clock &OneShoot,sf::Texture *texture) {
    if (OneShoot.getElapsedTime().asMilliseconds() >= 1000) {
        bullets.push_back(sf::CircleShape());
        bullets.back().setTexture(texture);
        bullets.back().setRadius(10);
        bullets.back().setOrigin(0,0); //-40, -65
        bullets.back().setPosition(ghostBor.getPosition().x+40,ghostBor.getPosition().y+65);

        int x;
        int y;

        x = 5 * cos(atan2(shape2.getPosition().y - ghostHeart.getPosition().y,
                          shape2.getPosition().x - ghostHeart.getPosition().x));
        y = 5 * sin(atan2(shape2.getPosition().y - ghostHeart.getPosition().y,
                          shape2.getPosition().x - ghostHeart.getPosition().x));
        xpos.push_back(x);
        ypos.push_back(y);
        OneShoot.restart();
    }
}
