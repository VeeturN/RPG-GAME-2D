//
// Created by dawid on 21.05.2024.
//

#include "Bot1.h"

Bot1::Bot1(sf::Texture *texture) {
    bot.setSize(sf::Vector2f(150, 150));
    bot.setTexture(texture);
    bot.setPosition(1900, 330);

    Animation animation(texture);
    Bot1::an=animation;
}

void Bot1::draw(sf::RenderWindow &window,sf::Clock &BotIddle,sf::RectangleShape& Player,sf::Text &info) {


    info.setPosition({1920, 280});
    info.setFillColor(sf::Color::Black);

    an.update(0, BotIddle);
    bot.setTextureRect(an.uvRect);
    window.draw(bot);
    window.draw(info);
}
