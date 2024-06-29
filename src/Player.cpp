//
// Created by dawid on 03.05.2024.
//

#include "Player.h"
#include "fmt/core.h"
#include "Animation.h"
#include <vector>
#include <random>

Player::Player(sf::Texture *texture) {
    Player::row= 0;
    shape.setSize(sf::Vector2f(150, 150));
    shape.setTexture(texture);
    shape.setPosition(1088+100, 100);
    //shape.setPosition(100, 100);

    shape2.setSize(sf::Vector2f(40,64));
    shape2.setFillColor(sf::Color::Yellow);

    PlayerHeart.setSize(sf::Vector2f(5,5));
    PlayerHeart.setFillColor(sf::Color::Yellow);

    AttackRage.setSize(sf::Vector2f(80,104));
    AttackRage.setFillColor(sf::Color::Yellow);

    border1.setSize(sf::Vector2f(40,64));
    border1.setFillColor(sf::Color::Black);

    border2.setSize(sf::Vector2f(40,64));
    border2.setFillColor(sf::Color::Black);

    border3.setSize(sf::Vector2f(40,64));
    border3.setFillColor(sf::Color::Black);

    border4.setSize(sf::Vector2f(40,64));
    border4.setFillColor(sf::Color::Black);

    Animation animation(texture);
    Player::a=animation;

    font.loadFromFile("../fontt.ttf");
    CoinShow=sf::Text(std::to_string(Coin),
                      font, 40);
    HpShow=sf::Text(std::to_string(HealthPlayer),
                      font, 40);

    chest1.loadFromFile("../sprites/objects/chest2.png");

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 1);
    ch1=1;
    ch2=distribution(generator);
    ch3=distribution(generator);
    ch4=distribution(generator);
    ch5=distribution(generator);
}



void Player::draw(sf::RenderWindow& window,Ghost& ghost1,Wizard& wizard) {
    window.draw(shape);
    Player::chest(window);
    Player::stats();
    CoinShow.setFillColor(sf::Color::Black);
    CoinShow.setString("Coin "+std::to_string(Coin));

    HpShow.setFillColor(sf::Color::Black);
    HpShow.setString("HP: "+std::to_string(HealthPlayer));
    window.draw(CoinShow);
    window.draw(HpShow);


    for (int i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[i]);
        bullets[i].move(xpos[i],ypos[i]);

        if (bullets[i].getGlobalBounds().intersects(ghost1.ghostBor.getGlobalBounds())) {
            ghost1.GhostHp--;
            xpos[i]=0;
            ypos[i]=0;
            bullets[i].setPosition(-10,-10);
        }

        if (bullets[i].getGlobalBounds().intersects(wizard.wizardBor.getGlobalBounds())) {
            wizard.WizardHp--;
            xpos[i]=0;
            ypos[i]=0;
            bullets[i].setPosition(-10,-10);
        }
        if (bullets[i].getPosition().x<-12 or bullets[i].getPosition().x>3400 or bullets[i].getPosition().y<-12 or bullets[i].getPosition().y>1602){
            bullets[i].setPosition(-10,-10);
            xpos[i]=0;
            ypos[i]=0;
        }
    }
}

void Player::speed(sf::Clock& clock,sf::RenderWindow& window,sf::Clock& clockPlayerAttack,std::vector<Skeleton>& skeleton,std::vector<Skeleton2>& skeleton2,std::vector<Skeleton3>& skeleton3,Ghost& ghost,Inject& i) {
    if (HealthPlayer<=0){
        a.dead(9,clock);
        shape.setTextureRect(a.uvRect5);
    } else{

        if (Player::Dpres){
            shape.move(Player::moveSpeed,0);
            border1.setPosition(shape.getPosition().x+58,shape.getPosition().y+70);
            a.update(1,clock);

            i.drawM1(window,border1,shape,1,moveSpeed);
            i.drawM2(window,border1,shape,1,moveSpeed);
            i.drawM3(window,border1,shape,1,moveSpeed);
            i.drawM4(window,border1,shape,1,moveSpeed);
            i.drawM5(window,border1,shape,1,moveSpeed);
            i.drawM6(window,border1,shape,1,moveSpeed);

            if (Spacepres) {
                a.PlayerAttack(7, clockPlayerAttack);
                shape.setTextureRect(a.uvRect4);

                Player::skeletonHit(skeleton,skeleton2,skeleton3);
                } else{
                    shape.setTextureRect(a.uvRect);
                }
        }

        if (Player::Wpres){
            shape.move(0,-Player::moveSpeed);
            border2.setPosition(shape.getPosition().x+56,shape.getPosition().y+68);
            a.update(2,clock);

            i.drawM1(window,border2,shape,2,moveSpeed);
            i.drawM2(window,border2,shape,2,moveSpeed);
            i.drawM3(window,border2,shape,2,moveSpeed);
            i.drawM4(window,border2,shape,2,moveSpeed);
            i.drawM5(window,border2,shape,2,moveSpeed);
            i.drawM6(window,border2,shape,2,moveSpeed);

            if (Spacepres){
                a.PlayerAttack(8,clockPlayerAttack);
                shape.setTextureRect(a.uvRect4);
                Player::skeletonHit(skeleton,skeleton2,skeleton3);
            } else{
                shape.setTextureRect(a.uvRect);
            }
        }
        if (Player::Apres){
            shape.move(-Player::moveSpeed,0);
            border3.setPosition(shape.getPosition().x+54,shape.getPosition().y+70);
            a.update(10,clock);

            i.drawM1(window,border3,shape,3,moveSpeed);
            i.drawM2(window,border3,shape,3,moveSpeed);
            i.drawM3(window,border3,shape,3,moveSpeed);
            i.drawM4(window,border3,shape,3,moveSpeed);
            i.drawM5(window,border3,shape,3,moveSpeed);
            i.drawM6(window,border3,shape,3,moveSpeed);

            if (Spacepres){
                a.PlayerAttack(11,clockPlayerAttack);
                shape.setTextureRect(a.uvRect4);
                Player::skeletonHit(skeleton,skeleton2,skeleton3);
            } else{
                shape.setTextureRect(a.uvRect);
            }
        }
        if (Player::Spres){
            shape.move(0,Player::moveSpeed);
            border4.setPosition(shape.getPosition().x+56,shape.getPosition().y+72);
            a.update(3,clock);

            i.drawM1(window,border4,shape,4,moveSpeed);
            i.drawM2(window,border4,shape,4,moveSpeed);
            i.drawM3(window,border4,shape,4,moveSpeed);
            i.drawM4(window,border4,shape,4,moveSpeed);
            i.drawM5(window,border4,shape,4,moveSpeed);
            i.drawM6(window,border4,shape,4,moveSpeed);

            if (Spacepres){

                a.PlayerAttack(6, clockPlayerAttack);
                shape.setTextureRect(a.uvRect4);
                Player::skeletonHit(skeleton,skeleton2,skeleton3);

            } else{
                shape.setTextureRect(a.uvRect);
            }
        }

        if (!(Dpres or Apres or Spres or Wpres)){
            a.iddle(clock);
            a.uvRect.top=0;

            if (Spacepres){
                a.PlayerAttack(6,clockPlayerAttack);
                shape.setTextureRect(a.uvRect4);
                Player::skeletonHit(skeleton,skeleton2,skeleton3);
            } else if(Lpress){

            } else{
                shape.setTextureRect(a.uvRect);
            }
        }
        }

    shape2.setPosition(shape.getPosition().x+58,shape.getPosition().y+70);
    AttackRage.setPosition(shape.getPosition().x+38,shape.getPosition().y+50);
    PlayerHeart.setPosition(shape.getPosition().x+75,shape.getPosition().y+90);

}

void Player::move(sf::RenderWindow& window,sf::Event &event,sf::Clock& clock10) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        Wpres = true;
    } else{
        Wpres = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        Apres = true;
    } else{
        Apres = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        Spres = true;
    } else{
        Spres = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        Dpres = true;
    } else{
        Dpres = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Spacepres = true;
    } else{
        Spacepres = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        Lpress = true;
    } else{
        Lpress = false;
    }
    if (GunUnlock) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (clock10.getElapsedTime().asMilliseconds() >= 600) {
                bullets.push_back(sf::CircleShape());
                bullets.back().setRadius(10);
                bullets.back().setOrigin(0, 0);
                bullets.back().setPosition(shape2.getPosition());

                int x;
                int y;


                if (shape2.getPosition().x > 2304) {
                    if (shape2.getPosition().y > 832) {
                        x = 5 * cos(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 2304 - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 2304 - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    } else {
                        x = 5 * cos(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 2304 - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 2304 - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    }
                } else if (shape2.getPosition().x > 1152) {
                    if (shape2.getPosition().y > 832) {
                        x = 5 * cos(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 1152 - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 1152 - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    } else {
                        x = 5 * cos(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 1152 - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x + 1152 - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    }
                } else {
                    if (shape2.getPosition().y > 832) {
                        x = 5 * cos(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y + 832 - PlayerHeart.getPosition().y,
                                          event.mouseButton.x - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    } else {
                        x = 5 * cos(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x - PlayerHeart.getPosition().x));
                        y = 5 * sin(atan2(event.mouseButton.y - PlayerHeart.getPosition().y,
                                          event.mouseButton.x - PlayerHeart.getPosition().x));
                        xpos.push_back(x);
                        ypos.push_back(y);
                    }
                }
                clock10.restart();
            }
        }
    }
}

Player::Player() {

}

void Player::stats() {
    if (shape2.getPosition().x>2304){
        if (shape2.getPosition().y>832){
            CoinShow.setPosition({3272,1552});
            HpShow.setPosition(3162,1552);
        } else{
            CoinShow.setPosition({3272,720});
            HpShow.setPosition(3162,720);
        }
    } else if(shape2.getPosition().x>1152){
        if (shape2.getPosition().y>832){
            CoinShow.setPosition({2120,1552});
            HpShow.setPosition(2010,1552);

        } else{
            CoinShow.setPosition({2120,720});
            HpShow.setPosition(2010,720);
        }
    } else{
        if (shape2.getPosition().y>832){
            CoinShow.setPosition({968,1552});
            HpShow.setPosition(858,1552);

        } else{
            CoinShow.setPosition({968,720});
            HpShow.setPosition(858,720);
        }
    }
}

void Player::skeletonHit(std::vector<Skeleton>& skeleton,std::vector<Skeleton2>& skeleton2,std::vector<Skeleton3>& skeleton3) {
    for (Skeleton& ss:skeleton) {
        if (AttackRage.getGlobalBounds().intersects(ss.skeletonBor.getGlobalBounds())) {
            ss.SkeletonHP--;
        }
    }
    for (Skeleton2& ss:skeleton2) {
        if (AttackRage.getGlobalBounds().intersects(ss.skeletonBor.getGlobalBounds())) {
            ss.SkeletonHP--;
        }
    }
    for (Skeleton3& ss:skeleton3) {
        if (AttackRage.getGlobalBounds().intersects(ss.skeletonBor.getGlobalBounds())) {
            ss.SkeletonHP--;
        }
    }
}

void Player::chest(sf::RenderWindow& window) {
    Player::chestCollect();
    if (ch1==1) {
        Chest1.setTexture(chest1);
        Chest1.setScale(3.4, 3.4);
        Chest1.setPosition(1600, 75);
        window.draw(Chest1);
    }
    if (ch2 == 1) {
        Chest2.setTexture(chest1);
        Chest2.setScale(3.4, 3.4);
        Chest2.setPosition(2180, 150);
        window.draw(Chest2);
    }
    if (ch3 == 1) {
        Chest3.setTexture(chest1);
        Chest3.setScale(3.4, 3.4);
        Chest3.setPosition(1200, 850);
        window.draw(Chest3);
    }
    if (ch4 == 1) {
        Chest4.setTexture(chest1);
        Chest4.setScale(3.4, 3.4);
        Chest4.setPosition(3300, 1500);
        window.draw(Chest4);
    }
    if (ch5 == 1) {
        Chest5.setTexture(chest1);
        Chest5.setScale(3.4, 3.4);
        Chest5.setPosition(780, 970);
        window.draw(Chest5);
    }
}

void Player::chestCollect() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        if (shape2.getGlobalBounds().intersects(Chest1.getGlobalBounds())) {
            ch1=0;
            Coin=Coin+8;
            Chest1.setPosition(-100, -100);
        }
        if (shape2.getGlobalBounds().intersects(Chest2.getGlobalBounds())) {
            ch2=0;
            Coin=Coin+8;
            Chest2.setPosition(-100, -100);
        }
        if (shape2.getGlobalBounds().intersects(Chest3.getGlobalBounds())) {
            ch3=0;
            Coin=Coin+8;
            Chest3.setPosition(-100, -100);
        }
        if (shape2.getGlobalBounds().intersects(Chest4.getGlobalBounds())) {
            ch4=0;
            Coin=Coin+8;
            Chest4.setPosition(-100, -100);
        }
        if (shape2.getGlobalBounds().intersects(Chest5.getGlobalBounds())) {
            ch5=0;
            Coin=Coin+8;
            Chest5.setPosition(-100, -100);
        }
    }
}
