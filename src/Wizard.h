//
// Created by dawid on 20.05.2024.
//

#ifndef GAME3_WIZARD_H
#define GAME3_WIZARD_H

#include "Animation.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics.hpp"

struct Wizard {
        sf::RectangleShape wizard;
        sf::RectangleShape wizardBor;
        sf::RectangleShape wizardHeart;

        std::vector<sf::CircleShape> bullets;
        std::vector<float> angel;
        std::vector<float> xpos;
        std::vector<float> ypos;

        sf::Texture ShotTexture;

        int row;
        double speed = 2;
        sf::Vector2f moveOn;
        int WizardHp=30;
        int x;
        int y;

        Animation an;

        Wizard(sf::Texture *texture);
        void draw(sf::RenderWindow &window,sf::RectangleShape shape2);
        void move(sf::Clock& clock, sf::Clock &clock2,sf::Clock& WizardMultiShoot, sf::RenderWindow& window, sf::RectangleShape PlayerHeart, sf::Texture *texture,sf::Texture *texture2);
        void shoot(sf::RectangleShape shape2,sf::Clock &WizardMultiShoot,sf::Texture *texture);
        void oneshoot(sf::RectangleShape shape2,sf::Clock &OneShoot,sf::Texture *texture2);
};


#endif //GAME3_WIZARD_H
