//
// Created by dawid on 21.05.2024.
//

#ifndef GAME3_BOT1_H
#define GAME3_BOT1_H
#pragma once


#include "SFML/Graphics/RectangleShape.hpp"
#include "Animation.h"
#include "Player.h"

struct Bot1 {
        sf::RectangleShape bot;
        sf::RectangleShape botBor;

        Animation an;

    Bot1(sf::Texture *texture);
    void draw(sf::RenderWindow &window,sf::Clock &BotIddle,sf::RectangleShape& Player,sf::Text& info);

};


#endif //GAME3_BOT1_H
