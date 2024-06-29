//
// Created by dawid on 06.05.2024.
//

#include <map>
#include "TitleMap.h"
#include "fmt/core.h"
#include "SFML/Graphics/Texture.hpp"

//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE
//NIE WYWOŁANA ZOSTAJE NA PAMIATKE

TitleMap::TitleMap(sf::RenderWindow &window) {
    mapX=window.getSize().x;
    mapX=window.getSize().y;

}

void TitleMap::test1(sf::RenderWindow &window,sf::RectangleShape& champ) {

    std::map<int,std::string> mapa;
    mapa[1]="../sprites/tilesets/grass.png";
    mapa[2]="../sprites/tilesets/grasstop.png";
    mapa[3]="../sprites/tilesets/grassbot.png";
    mapa[4]="../sprites/tilesets/grassl.png";
    mapa[5]="../sprites/tilesets/grassr.png";
    mapa[6]="../sprites/tilesets/grass1.png";
    mapa[7]="../sprites/tilesets/grass2.png";
    mapa[8]="../sprites/tilesets/grass3.png";
    mapa[9]="../sprites/tilesets/grass4.png";
    mapa[10]="../sprites/tilesets/grass11.png";
    mapa[11]="../sprites/tilesets/grass22.png";
    mapa[12]="../sprites/tilesets/grass33.png";
    mapa[13]="../sprites/tilesets/grass44.png";
    mapa[14]="../sprites/tilesets/wooden.png";
    mapa[15]="../sprites/tilesets/walls.png";
    mapa[16]="../sprites/tilesets/walls1.png";
    mapa[17]="../sprites/tilesets/walls2.png";
    mapa[18]="../sprites/tilesets/w1.png";
    mapa[19]="../sprites/tilesets/w2.png";
    mapa[20]="../sprites/tilesets/w3.png";
    mapa[21]="../sprites/tilesets/w4.png";
    mapa[22]="../sprites/tilesets/w5.png";
    mapa[23]="../sprites/tilesets/w6.png";
    mapa[24]="../sprites/tilesets/w7.png";
    mapa[25]="../sprites/tilesets/w8.png";
    mapa[26]="../sprites/tilesets/w9.png";
    mapa[27]="../sprites/tilesets/w10.png";
    mapa[28]="../sprites/tilesets/w11.png";


    std::vector<int> vec{
            15,16,16,16,16,16,16,16,17,1,1,1,1,1,1,1,1,
            15,14,14,14,14,14,14,14,17,1,20,19,19,19,21,1,1,
            15,14,14,14,14,14,14,14,17,1,23,27,27,28,25,21,1,
            15,14,14,14,14,14,14,14,17,1,1,1,1,26,18,25,19,
            15,16,16,16,14,16,16,16,17,1,7,8,1,26,18,18,18,
            1,1,1,1,1,1,1,1,1,1,4,5,1,23,27,27,27,
            1,7,2,2,2,2,2,2,2,2,11,5,1,1,1,1,1,
            1,6,3,3,3,3,3,3,3,3,10,5,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,4,12,2,2,8,1,1,
            1,1,1,1,1,1,1,1,1,1,6,3,3,10,5,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,4,5,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,4,5,1,1,
            1,14,14,14,14,1,1,1,1,1,1,1,1,4,5,1,1
    };
    int one=0;
    int two=0;
    int num=0;
    for (int i = 0; i < 12; ++i) {
        two=0;
        for (int j = 0; j < 17; ++j) {
            sf::RectangleShape x;
            x.setSize(sf::Vector2f(64, 64));
            x.setPosition(0+two,0+one);
            sf::Texture tx;
            std::string ok=mapa[num];
            tx.loadFromFile(mapa[vec[num]]);
            x.setTexture(&tx);
            window.draw(x);
            two+=64;
            num++;
        }
        one+=64;
    }
    sf::RectangleShape xd;
    xd.setSize(sf::Vector2f(180, 250));
    xd.setPosition(50,530);
    sf::Texture txd;
    txd.loadFromFile("../sprites/objects/tree.png");
    xd.setTexture(&txd);
    window.draw(xd);
}



