//
// Created by dawid on 14.05.2024.
//

#ifndef GAME3_GHOST_H
#define GAME3_GHOST_H
#pragma once
#include "Animation.h"
#include "SFML/Graphics/Texture.hpp"


struct Ghost {
    sf::RectangleShape ghost;
    sf::RectangleShape ghostBor;
    sf::RectangleShape ghostHeart;

    std::vector<sf::CircleShape> bullets;
    std::vector<float> angel;
    std::vector<float> xpos;
    std::vector<float> ypos;

    sf::Texture ShotTexture;

    int row;
    double speed = 2;
    sf::Vector2f moveOn;
    int GhostHp=25;
    int x;
    int y;

    Animation an;

    Ghost(sf::Texture *texture);
    void draw(sf::RenderWindow &window,sf::RectangleShape shape2);
    void move(sf::Clock& clock, sf::Clock &clock2, sf::RenderWindow& window, sf::RectangleShape& PlayerHeart, sf::Texture *texture);
    void shoot(sf::RectangleShape shape2,sf::Texture *texture);
    void oneshoot(sf::RectangleShape shape2,sf::Clock &OneShoot,sf::Texture *texture);
};


#endif //GAME3_GHOST_H
