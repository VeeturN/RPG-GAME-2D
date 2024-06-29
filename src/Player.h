//
// Created by dawid on 03.05.2024.
//

#ifndef GAME2_PLAYER_H
#define GAME2_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "Wizard.h"
#include <math.h>
#include "Inject.h"
#include "Skeleton3.h"
#include "Skeleton2.h"

#pragma once

struct Player{
    sf::RectangleShape shape;
    sf::RectangleShape shape2;
    sf::RectangleShape AttackRage;
    sf::RectangleShape PlayerHeart;

    sf::RectangleShape border1;
    sf::RectangleShape border2;
    sf::RectangleShape border3;
    sf::RectangleShape border4;

    sf::Texture chest1;
    sf::Sprite Chest1;
    sf::Sprite Chest2;
    sf::Sprite Chest3;
    sf::Sprite Chest4;
    sf::Sprite Chest5;

    int ch1;
    int ch2;
    int ch3;
    int ch4;
    int ch5;

    std::vector<sf::CircleShape> bullets;
    std::vector<float> angel;
    std::vector<float> xpos;
    std::vector<float> ypos;

    sf::Font font;
    sf::Text CoinShow;
    sf::Text HpShow;

    static inline float moveSpeed=5;
    static inline int HealthPlayer=6;
    static inline int Coin=0;
    int row;
    bool face;

    Animation a;

    bool Wpres= false;
    bool Apres= false;
    bool Spres= false;
    bool Dpres= false;
    bool Spacepres= false;
    bool Lpress= false;
    static inline bool GunUnlock= false;

    Player(sf::Texture *texture);
    Player();


    void draw(sf::RenderWindow& window,Ghost& ghost1,Wizard& wizard);
    void move(sf::RenderWindow& window,sf::Event& event,sf::Clock& clock10);
    void speed(sf::Clock& clock,sf::RenderWindow& window,sf::Clock& clockPlayerAttack,std::vector<Skeleton>& skeleton,std::vector<Skeleton2>& skeleton2,std::vector<Skeleton3>& skeleton3,Ghost& ghost,Inject& i);
    void stats();
    void chestCollect();
    void chest(sf::RenderWindow& window);
    void skeletonHit(std::vector<Skeleton>& skeleton,std::vector<Skeleton2>& skeleton2,std::vector<Skeleton3>& skeleton3);
};


#endif //GAME2_PLAYER_H
