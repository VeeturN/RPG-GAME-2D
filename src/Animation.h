//
// Created by dawid on 04.05.2024.
//
#pragma once
#include "SFML/Graphics.hpp"


#ifndef GAME2_ANIMATION_H
#define GAME2_ANIMATION_H


struct Animation {
    Animation(sf::Texture* texture);
    Animation();
    ~Animation();

    void update(int row, sf::Clock& clock);
    void iddle(sf::Clock& clock);
    void PlayerAttack(int row, sf::Clock& clockPlayerAttack);
    void dead(int row, sf::Clock& clock);

    void skeleton(int row,sf::Clock& clock);
    void skeletonAttack(int row,sf::Clock &clock1);
    void skeletonDead(int row,sf::Clock &clock1);

    void ghost(int row,sf::Clock& clock);
    void ghostIddle(int row, sf::Clock &clock);
    void ghostDead(int row, sf::Clock &clock);
    void ghostAttack(int row, sf::Clock &clock);

    void wizard(int row,sf::Clock& clock);
    void wizardIddle(int row, sf::Clock &clock);
    void wizardDead(int row, sf::Clock &clock);
    void wizardAttack(int row, sf::Clock &clock);

    void DMG();


    sf::IntRect uvRect;
    sf::IntRect uvRect2;
    sf::IntRect uvRect3;
    sf::IntRect uvRect4;
    sf::IntRect uvRect5;
    sf::IntRect uvRect6;

    sf::IntRect uvRect7;
    sf::IntRect uvRect8;
    sf::IntRect uvRect9;
    sf::IntRect uvRect10;

    sf::IntRect wizarduvRect;
    sf::IntRect wizardIddleuvRect;
    sf::IntRect wizardDeaduvRect;
    sf::IntRect wizardAttackuvRect;



    int pos;
    int time=0;
    int timer=1;
    int CoinCount=0;
};


#endif //GAME2_ANIMATION_H
