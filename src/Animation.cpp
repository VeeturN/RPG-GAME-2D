//
// Created by dawid on 04.05.2024.
//

#include <random>
#include "Animation.h"
#include "Player.h"
#include "fmt/core.h"

Animation::Animation(sf::Texture *texture) {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 6);
    CoinCount = distribution(generator);
}
Animation::~Animation(){

}

void Animation::update(int row, sf::Clock& clock) {
    uvRect.top = row * 64;
    uvRect.height = 64;
    uvRect.width = 64;
    if (clock.getElapsedTime().asMilliseconds() >= 100) {
        if (uvRect.left == 320)
            uvRect.left = 0;
        else
            uvRect.left += 64;

        clock.restart();
    }
}
void Animation::iddle(sf::Clock& clock){
    if (clock.getElapsedTime().asMilliseconds()>=100){
        if (uvRect.left==320)
            uvRect.left=0;
        else
            uvRect.left+=64;

        clock.restart();
    }
}
void Animation::dead(int row, sf::Clock& clock) {

    uvRect5.top = row * 64;
    uvRect5.height = 64;
    uvRect5.width = 64;
    if (clock.getElapsedTime().asMilliseconds() >= 1000) {
        if (uvRect5.left >= 128) {

        }
        else
            uvRect5.left += 64;

        clock.restart();
    }
}

void Animation::PlayerAttack(int row, sf::Clock& clockPlayerAttack){
    uvRect4.top = row * 64;
    uvRect4.height = 64;
    uvRect4.width = 64;

    if (clockPlayerAttack.getElapsedTime().asMilliseconds() >= 100) {
        if (uvRect4.left == 192)
            uvRect4.left = 0;
        else
            uvRect4.left += 64;

        clockPlayerAttack.restart();
    }
}



void Animation::skeleton(int row,sf::Clock &clock1) {
    uvRect2.top = row * 64;
    uvRect2.height = 64;
    uvRect2.width = 64;

    if (clock1.getElapsedTime().asMilliseconds() >= 200) {
        if (uvRect2.left == 320)
            uvRect2.left = 0;
        else
            uvRect2.left += 64;

        clock1.restart();
    }
}

void Animation::skeletonAttack(int row,sf::Clock &clock1){

    uvRect3.top = row * 64;
    uvRect3.height = 64;
    uvRect3.width = 64;

    if (clock1.getElapsedTime().asMilliseconds() >= 150) {
        if (uvRect3.left == 256) {
            uvRect3.left = 0;
            Player::HealthPlayer--;
            fmt::println("{}",Player::HealthPlayer);
        }
        else {
            uvRect3.left += 64;
        }
        clock1.restart();
    }
}

void Animation::skeletonDead(int row, sf::Clock& clock) {
    uvRect6.top = row * 64;
    uvRect6.height = 64;
    uvRect6.width = 64;
    if (clock.getElapsedTime().asMilliseconds() >= 200) {
        if (uvRect6.left >= 256) {

        }
        else {
            if (uvRect6.left==192){
                Player::Coin+=CoinCount;
                fmt::println("{} TUUUUUUU",CoinCount);
            }
            uvRect6.left += 64;
        }
        clock.restart();
    }
}

void Animation::ghost(int row, sf::Clock &clock) {
    uvRect7.top = row * 80;
    uvRect7.height = 80;
    uvRect7.width = 80;

    if (clock.getElapsedTime().asMilliseconds() >= 300) {
        if (uvRect7.left == 400) {
            uvRect7.left = 0;
                timer++;
        }else
            uvRect7.left += 80;

        clock.restart();
    }
}

void Animation::ghostIddle(int row, sf::Clock &clock) {
    uvRect8.top = row * 80;
    uvRect8.height = 80;
    uvRect8.width = 80;

    if (clock.getElapsedTime().asMilliseconds() >= 300) {
        if (uvRect8.left == 720)
            uvRect8.left = 0;
        else
            uvRect8.left += 80;

        clock.restart();
    }
}

void Animation::ghostDead(int row, sf::Clock &clock) {

    uvRect9.top = row * 80;
    uvRect9.height = 80;
    uvRect9.width = 80;
    if (clock.getElapsedTime().asMilliseconds() >= 250) {
        if (uvRect9.left >= 720) {

        }
        else {
            if (uvRect9.left==640){
                Player::Coin+=10;
            }
            uvRect9.left += 80;
        }
        clock.restart();
    }
}
void Animation::ghostAttack(int row, sf::Clock &clock) {

    uvRect10.top = row * 80;
    uvRect10.height = 80;
    uvRect10.width = 80;
    if (clock.getElapsedTime().asMilliseconds() >= 400) {
        if (uvRect10.left >= 560) {
            if (timer==6)
                timer=1;
            else
                timer++;
            uvRect10.left = 0;
        }
        else
            uvRect10.left += 80;

        clock.restart();
    }
}

void Animation::wizard(int row, sf::Clock &clock) {
    wizarduvRect.top = row * 80;
    wizarduvRect.height = 80;
    wizarduvRect.width = 80;

    if (clock.getElapsedTime().asMilliseconds() >= 400) {
        if (wizarduvRect.left == 560) {
            wizarduvRect.left = 0;
            timer++;
        }else
            wizarduvRect.left += 80;

        clock.restart();
    }
}

void Animation::wizardIddle(int row, sf::Clock &clock) {
    wizardIddleuvRect.top = row * 80;
    wizardIddleuvRect.height = 80;
    wizardIddleuvRect.width = 80;

    if (clock.getElapsedTime().asMilliseconds() >= 300) {
        if (wizardIddleuvRect.left == 400)
            wizardIddleuvRect.left = 0;
        else
            wizardIddleuvRect.left += 80;

        clock.restart();
    }
}

void Animation::wizardDead(int row, sf::Clock &clock) {

    wizardDeaduvRect.top = row * 80;
    wizardDeaduvRect.height = 80;
    wizardDeaduvRect.width = 80;
    if (clock.getElapsedTime().asMilliseconds() >= 250) {
        if (wizardDeaduvRect.left >= 480) {

        }
        else {
            if (wizardDeaduvRect.left==400){
                Player::Coin+=10;
            }
            wizardDeaduvRect.left += 80;
        }
        clock.restart();
    }
}
void Animation::wizardAttack(int row, sf::Clock &clock) {

    wizardAttackuvRect.top = row * 80;
    wizardAttackuvRect.height = 80;
    wizardAttackuvRect.width = 80;
    if (clock.getElapsedTime().asMilliseconds() >= 400) {
        if (wizardAttackuvRect.left >= 560) {
            if (timer==6)
                timer=1;
            else
                timer++;
            wizardAttackuvRect.left = 0;
        }
        else
            wizardAttackuvRect.left += 80;

        clock.restart();
    }
}

Animation::Animation() {

}

void Animation::DMG() {
    Player::HealthPlayer--;
}


