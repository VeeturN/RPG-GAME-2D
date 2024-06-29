//
// Created by dawid on 06.05.2024.
//

#ifndef GAME2_TITLEMAP_H
#define GAME2_TITLEMAP_H


#include <string>
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE


struct TitleMap {
    int mapX;
    int mapY;
    sf::RectangleShape kwadrat;
//    int one;
//    int two;

    TitleMap(sf::RenderWindow & window);

    void test1(sf::RenderWindow &window,sf::RectangleShape& champ);
    void MAP2(sf::RenderWindow &window,sf::RectangleShape& champ);
    void draw(sf::RenderWindow &window);

};


#endif //GAME2_TITLEMAP_H
