//
// Created by dawid on 27.05.2024.
//

#ifndef GAME3_SKELETON2_H
#define GAME3_SKELETON2_H
#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"

struct Skeleton2 {
    sf::RectangleShape skeleton;
    sf::RectangleShape skeletonBor;
    sf::Vector2f moveOn;
    sf::RectangleShape bor1;
    sf::RectangleShape bor2;
    sf::RectangleShape bor3;
    sf::RectangleShape bor4;
    sf::Clock clock1;

    int row;
    double speed;
    int SkeletonHP=100;
    int x;
    int y;

    Animation an;

    Skeleton2(sf::Texture *texture, sf::Clock clock);

    Skeleton2();

    void draw(sf::RenderWindow& window);
    void move(sf::RenderWindow& window,sf::RectangleShape shape2);
};


#endif //GAME3_SKELETON2_H
