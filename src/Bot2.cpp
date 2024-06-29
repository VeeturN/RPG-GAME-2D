//
// Created by dawid on 21.05.2024.
//

#include "Bot2.h"
#include "fmt/core.h"

Bot2::Bot2(sf::Texture *texture) {
    bot.setSize(sf::Vector2f(150, 150));
    bot.setTexture(texture);
    bot.setPosition(1400, 570);

    botBor.setSize({200,200});
    botBor.setPosition(1380,500);

    shop.setSize({480, 330});
    shop.setPosition(1760,0);
    shop.setFillColor(sf::Color::Black);

    shop1.setSize({120, 120});
    shop1.setPosition(1790,30);
    shop1.setFillColor(sf::Color::Green);

    shop2.setSize({120, 120});
    shop2.setPosition(1940,30);
    shop2.setFillColor(sf::Color::Green);

    shop3.setSize({120, 120});
    shop3.setPosition(2090,30);
    shop3.setFillColor(sf::Color::Green);

    shop4.setSize({120, 120});
    shop4.setPosition(1790,180);
    shop4.setFillColor(sf::Color::Green);

    shop5.setSize({120, 120});
    shop5.setPosition(1940,180);
    shop5.setFillColor(sf::Color::Green);

    shop6.setSize({120, 120});
    shop6.setPosition(2090,180);
    shop6.setFillColor(sf::Color::Green);

    Animation animation(texture);
    Bot2::an=animation;


    heart.loadFromFile("../sprites/objects/Heart.png");
    Heart.setTexture(heart);
    Heart.setScale(9,9);
    Heart.setPosition(1810,45);

    gun.loadFromFile("../sprites/objects/gun.png");
    Gun.setTexture(gun);
    Gun.setScale(5,5);
    Gun.setPosition(2115,45);

    boots.loadFromFile("../sprites/objects/boots.png");
    Boots.setTexture(boots);
    Boots.setScale(0.3,0.3);
    Boots.setPosition(1960,40);
}

void Bot2::draw(sf::RenderWindow &window,sf::Clock &BotIddle,sf::RectangleShape& Player,sf::Text &info2,sf::Clock& ShopTime) {
    auto font = sf::Font();
    font.loadFromFile("../fontt.ttf");
    auto Price = sf::Text("3 \t\t\t 6 \t\t\t 30",
                          font, 40);
    Price.setFillColor(sf::Color::Black);
    Price.setPosition(1845,100);

    info2.setPosition({1380, 590});
    info2.setFillColor(sf::Color::Black);
    an.update(0, BotIddle);
    bot.setTextureRect(an.uvRect);
    window.draw(bot);
    if (Player.getGlobalBounds().intersects(botBor.getGlobalBounds())){
        window.draw(shop);
        window.draw(shop1);
        window.draw(shop2);
        window.draw(shop3);
        window.draw(shop4);
        window.draw(shop5);
        window.draw(shop6);
        window.draw(Heart);
        window.draw(Gun);
        window.draw(Boots);
        window.draw(Price);




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) and Player::Coin>=3){
            if (ShopTime.getElapsedTime().asMilliseconds() >= 400) {
                Player::HealthPlayer++;
                Player::Coin=Player::Coin-3;
                ShopTime.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) and Player::Coin>=6){
            if (ShopTime.getElapsedTime().asMilliseconds() >= 400) {
                Player::moveSpeed++;
                Player::Coin=Player::Coin-6;
                ShopTime.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) and Player::Coin>=30 and !Player::GunUnlock){
            shop3.setFillColor(sf::Color::Red);
            if (ShopTime.getElapsedTime().asMilliseconds() >= 400) {
                Player::GunUnlock= true;
                Player::Coin=Player::Coin-30;
                ShopTime.restart();
            }
        }
    } else {
        window.draw(info2);
    }
}


