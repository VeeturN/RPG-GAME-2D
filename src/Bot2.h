//
// Created by dawid on 21.05.2024.
//

#ifndef GAME3_BOT2_H
#define GAME3_BOT2_H


#pragma once


#include "SFML/Graphics/RectangleShape.hpp"
#include "Animation.h"
#include "Player.h"

struct Bot2 {
    sf::RectangleShape bot;
    sf::RectangleShape botBor;
    sf::RectangleShape shop;

    sf::RectangleShape shop1;
    sf::RectangleShape shop2;
    sf::RectangleShape shop3;
    sf::RectangleShape shop4;
    sf::RectangleShape shop5;
    sf::RectangleShape shop6;

    Animation an;

    Bot2(sf::Texture *texture);
    void draw(sf::RenderWindow &window,sf::Clock &BotIddle,sf::RectangleShape& Player,sf::Text &info2,sf::Clock& ShopTime);

    sf::Texture heart;
    sf::Sprite Heart;
    sf::Texture gun;
    sf::Sprite Gun;
    sf::Texture boots;
    sf::Sprite Boots;

};


#endif //GAME3_BOT2_H
