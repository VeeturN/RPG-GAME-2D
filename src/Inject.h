//
// Created by dawid on 08.05.2024.
//

#ifndef GAME2_INJECT_H
#define GAME2_INJECT_H
#include "SFML/Graphics.hpp"
#pragma once
struct Inject {
    //MAP 1
    sf::RectangleShape Map1w1;
    sf::RectangleShape Map1w2;
    sf::RectangleShape Map1w3;
    sf::RectangleShape Map1w4;
    sf::RectangleShape Map1w44;
    sf::RectangleShape Map1wLeft;
    sf::RectangleShape Map1wRight;
    sf::RectangleShape Map1wTop;
    sf::RectangleShape Map1wBot;
    sf::RectangleShape Map1wBot2;
    sf::RectangleShape Map1Water1;
    sf::RectangleShape Map1Water2;
    sf::RectangleShape Map1Water3;



    sf::RectangleShape MapRoom1;

    sf::Texture back;
    sf::Sprite Back;

    sf::Texture Tree;
    sf::Sprite Tree1;
    sf::Sprite Tree2;
    sf::Texture bed;
    sf::Sprite Bed;
    sf::Texture books;
    sf::Sprite Books;
    sf::Sprite Books2;
    sf::Texture hair;
    sf::Sprite Hair;
    sf::Texture bench;
    sf::Sprite Bench1;
    sf::Texture log;
    sf::Sprite Log;

    //MAP 2
    sf::RectangleShape Map2w1;
    sf::RectangleShape Map2w2;
    sf::RectangleShape Map2w3;
    sf::RectangleShape Map2w4;
    sf::RectangleShape Map2w44;
    sf::RectangleShape Map2w5;
    sf::RectangleShape Map2w55;
    sf::RectangleShape MapRoom2;
    sf::RectangleShape MapRoom2l;
    sf::RectangleShape MapRoom2r;
    sf::RectangleShape Map2Water1;
    sf::RectangleShape Map2Water2;

    //MAP 3
    sf::RectangleShape Map3w1;
    sf::RectangleShape Map3w2;
    sf::RectangleShape Map3w3;
    sf::RectangleShape Map3w4;
    sf::RectangleShape Map3w5;
    sf::RectangleShape Map3w55;
    sf::RectangleShape MapRoom3;
    sf::RectangleShape MapRoom3l;

    //MAP 4
    sf::RectangleShape Map4w1;
    sf::RectangleShape Map4w2;
    sf::RectangleShape Map4w3;
    sf::RectangleShape Map4w4;
    sf::RectangleShape Map4w5;
    sf::RectangleShape Map4w55;
    sf::RectangleShape MapRoom4;
    sf::RectangleShape MapRoom4r;
    sf::RectangleShape Map4Water1;
    sf::RectangleShape Map4Water2;
    sf::RectangleShape Map4Water3;
    sf::RectangleShape Map4Water4;
    sf::RectangleShape Map4Water5;


    //MAP 5
    sf::RectangleShape Map5w1;
    sf::RectangleShape Map5w2;
    sf::RectangleShape Map5w3;
    sf::RectangleShape Map5w4;
    sf::RectangleShape Map5w5;
    sf::RectangleShape Map5w55;
    sf::RectangleShape MapRoom5;

    //MAP 6
    sf::RectangleShape Map6w1;
    sf::RectangleShape Map6w2;
    sf::RectangleShape Map6w3;
    sf::RectangleShape Map6w4;
    sf::RectangleShape Map6w5;
    sf::RectangleShape Map6w55;
    sf::RectangleShape MapRoom6;

    Inject(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);

    void drawM1(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
    void drawM2(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
    void drawM3(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
    void drawM4(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
    void drawM5(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
    void drawM6(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed);
};


#endif //GAME2_INJECT_H
