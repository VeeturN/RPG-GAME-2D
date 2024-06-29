#include <iostream>
#include <fstream>
#include "fmt/core.h"
#include <filesystem>
#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics.hpp"

#include "Player.h"
#include "TileMap.h"
#include "Inject.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "Wizard.h"
#include "Bot1.h"
#include "Bot2.h"
#include "Skeleton2.h"
#include "Skeleton3.h"


int main() {
    auto window=sf::RenderWindow(
            sf::VideoMode({1088,768}),
            "GAME1",
            sf::Style::Close,
            sf::ContextSettings(0,0,8)
    );
    window.setFramerateLimit(60);

    //KREATOR MAPY
    const int level[] =
            {
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,34,19,19,19,19,19,19,19,49,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,34,4,4,4,4,4,4,4,49,2,91,31,31,31,61,2,2,4,2,2,2,2,2,2,2,2,2,92,47,47,47,47,122,2,2,
                    2,2,2,2,2,2,2,2,2,2,2,2,92,122,2,2,2,4,34,4,4,4,4,4,4,4,49,2,106,1,1,166,151,61,2,4,2,2,2,2,2,2,2,2,92,137,197,197,197,197,32,2,2,
                    2,2,2,2,2,2,2,2,2,2,2,92,137,182,122,2,2,4,34,4,4,4,4,4,4,4,49,2,2,2,2,16,121,151,31,4,2,2,2,2,2,2,2,92,137,197,197,197,197,197,32,2,2,
                    2,2,92,47,47,47,47,47,47,47,47,137,197,197,182,122,2,4,34,19,19,19,4,19,19,19,49,2,92,122,2,16,121,121,121,4,2,2,2,2,2,2,92,137,167,17,17,17,17,17,77,2,2,
                    2,2,62,167,17,17,17,17,17,17,17,152,197,197,167,77,2,4,2,2,2,2,2,2,2,2,2,2,62,32,2,106,1,1,1,4,2,2,2,2,2,92,137,167,77,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,107,152,167,77,2,2,4,2,92,47,47,47,47,47,47,47,47,137,32,2,2,2,2,2,4,2,2,2,2,92,137,167,77,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,107,77,2,2,2,4,2,107,17,17,17,17,17,17,17,17,152,32,2,2,2,2,2,4,2,2,2,92,137,167,77,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,2,2,91,31,4,2,2,2,2,2,2,2,2,2,2,62,182,47,47,122,2,2,4,2,2,92,137,167,77,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,
                    2,2,2,2,2,2,2,2,91,181,121,4,2,2,2,2,2,2,2,2,2,2,107,17,17,152,32,2,2,4,2,92,137,167,77,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,91,181,121,121,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,167,77,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,91,31,181,121,121,121,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
                    2,2,62,32,2,2,2,2,2,2,2,106,166,121,121,121,121,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,106,166,121,121,121,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,106,1,1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,62,32,2,2,4,2,62,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,62,182,47,122,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,92,47,47,47,137,182,47,47,4,47,137,32,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,107,17,152,182,122,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,92,137,167,17,17,17,17,17,17,4,17,17,77,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,2,2,107,152,182,47,47,47,47,47,47,47,47,47,47,4,47,47,47,47,47,47,47,47,137,167,77,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,2,2,2,107,17,17,17,17,17,17,17,17,17,17,17,4,17,17,17,17,17,17,17,17,17,77,2,2,2,2,91,31,31,4,31,31,31,31,61,2,2,2,2,2,2,2,2,2,2,2,2,
                    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,91,181,121,121,4,121,121,121,121,151,61,2,2,2,2,2,2,2,2,2,2,2
            };

    TileMap mapss;
    if (!mapss.load("../sprites/tilesets/Szablon2.png", sf::Vector2u(64, 64), level, 53, 25)) {
        return -1;
    }
   sf::View view(sf::FloatRect(1088+64, 0, 1088, 768));
 //sf::View view(sf::FloatRect(0, 0, 1088, 768));
    window.setView(view);



    Inject i(window);

    //PLAYER
    sf::Texture playerTexturee;
    playerTexturee.loadFromFile("../sprites/characters/playerV2V2.png");
    Player player(&playerTexturee);


    //SKELETON
    sf::Texture skeletonTexturee;
    sf::Clock clockSkeleton;
    skeletonTexturee.loadFromFile("../sprites/characters/skeletonV2.png");
    Skeleton skeleton(&skeletonTexturee, clockSkeleton);
    Skeleton skeleton2(&skeletonTexturee, clockSkeleton);
    Skeleton skeleton3(&skeletonTexturee, clockSkeleton);

    //SKELETON2
    Skeleton2 skeleton0(&skeletonTexturee, clockSkeleton);
    Skeleton2 skeleton22(&skeletonTexturee, clockSkeleton);
    Skeleton2 skeleton33(&skeletonTexturee, clockSkeleton);
    Skeleton2 skeleton44(&skeletonTexturee, clockSkeleton);
    Skeleton2 skeleton55(&skeletonTexturee, clockSkeleton);

    //SKELETON3
    Skeleton3 skeleton00(&skeletonTexturee, clockSkeleton);
    Skeleton3 skeleton222(&skeletonTexturee, clockSkeleton);
    Skeleton3 skeleton333(&skeletonTexturee, clockSkeleton);
    Skeleton3 skeleton444(&skeletonTexturee, clockSkeleton);
    Skeleton3 skeleton555(&skeletonTexturee, clockSkeleton);

    //SKELETON VEC
    std::vector<Skeleton> vec=std::vector<Skeleton>{skeleton,skeleton2,skeleton3};
    std::vector<Skeleton2> vec2=std::vector<Skeleton2>{skeleton0,skeleton22,skeleton33,skeleton44,skeleton55};
    std::vector<Skeleton3> vec3=std::vector<Skeleton3>{skeleton00,skeleton222,skeleton333,skeleton444,skeleton555};


    //GHOST
    sf::Texture GhostTexture;
    sf::Texture GhostTextureShot;
    GhostTexture.loadFromFile("../sprites/characters/Wizardd.png");
    GhostTextureShot.loadFromFile("../sprites/characters/Bullet.png");
    Ghost ghost(&GhostTexture);

    //WIZARD
    sf::Texture WizardTexture;
    sf::Texture WizardTextureShot;
    sf::Texture WizardTextureShotBig;
    WizardTexture.loadFromFile("../sprites/characters/WIZARD2.png");
    WizardTextureShot.loadFromFile("../sprites/characters/Ball.png");
    WizardTextureShotBig.loadFromFile("../sprites/characters/BallBig.png");
    Wizard wizard(&WizardTexture);

    //BOT1
    auto font = sf::Font();
    font.loadFromFile("../fontt.ttf");
    auto info = sf::Text("Hello newcomer, monsters have appeared\n in our village. Help us kill them and we will\n definitely return the favor. But remember \nto buy a pistol before the fight with \nthe Ghost and the Wizard.\n Good luck !",
                         font, 17);
    sf::Texture Bot1Texture;
    Bot1Texture.loadFromFile("../sprites/characters/BOT1.png");
    Bot1 bot1(&Bot1Texture);

    //BOT2
    auto info2 = sf::Text("Do you want to buy something ?",
                         font, 17);
    sf::Texture Bot2Texture;
    Bot2Texture.loadFromFile("../sprites/characters/BOT2.png");
    Bot2 bot2(&Bot2Texture);


    //ZEGARY
    sf::Clock clock;
    sf::Clock clockPlayerAttack;
    sf::Clock GhostMove;
    sf::Clock Clock10;
    sf::Clock Clock2;
    sf::Clock OneShoot;
    sf::Clock WizardMove;
    sf::Clock WizardOneShoot;
    sf::Clock WizardMultiShoot;
    sf::Clock BotIddle;
    sf::Clock Bot2Iddle;
    sf::Clock ShopTime;

    while (window.isOpen()){

        auto event=sf::Event();

        while (window.pollEvent(event)){

            if (event.type==sf::Event::Closed){
                window.close();
            }
            else if(event.type==sf::Event::KeyPressed){
                player.move(window,event,Clock10);
            }
            else if (event.type==sf::Event::KeyReleased){
                player.move(window,event,Clock10);
            }
            if (event.type==sf::Event::MouseButtonPressed){
                player.move(window, event,Clock10);
            }
        }

//        map.ChoseMap(player.shape,player.shape2);

        for(Skeleton& s:vec){
            s.move(window,player.shape2);
        }
        for(Skeleton2& s:vec2){
            s.move(window,player.shape2);
        }
        for(Skeleton3& s:vec3){
            s.move(window,player.shape2);
        }
        ghost.move(GhostMove,Clock2,window,player.PlayerHeart,&GhostTextureShot);
        wizard.move(WizardMove,WizardOneShoot,WizardMultiShoot,window,player.PlayerHeart,&WizardTextureShot,&WizardTextureShotBig);

        window.clear(sf::Color::Black);

        player.speed(clock,window,clockPlayerAttack,vec,vec2,vec3,ghost,i);
        window.draw(mapss);
//        map.draw(window);
        i.draw(window);

        for(Skeleton& s:vec){
            s.draw(window);
        }
        for(Skeleton2& s:vec2){
            s.draw(window);
        }
        for(Skeleton3& s:vec3){
            s.draw(window);
        }
        bot1.draw(window,BotIddle,player.shape2,info);
        bot2.draw(window,Bot2Iddle,player.shape2,info2,ShopTime);
        ghost.draw(window,player.shape2);
        wizard.draw(window,player.shape2);
        player.draw(window,ghost,wizard);
        window.display();
    }
}

