//
// Created by dawid on 08.05.2024.
//

#include "Inject.h"
#include "fmt/core.h"


void Inject::drawM1(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X, float speed) {
    Map1w1.setSize({1088,0.01});
    Map1w2.setSize({0.01,768});
    Map1w3.setSize({0.01,768});
    Map1w4.setSize({830,0.01});
    Map1w44.setSize({128,0.01});
    MapRoom1.setSize({130,0.01});

    Map1w1.setPosition(1152,0);
    Map1w2.setPosition(1152,0);
    Map1w3.setPosition(2240,0);
    Map1w4.setPosition(1152,768);
    Map1w44.setPosition(2112,768);
    MapRoom1.setPosition(1982,768);

    Map1wLeft.setSize({32,320});
    Map1wLeft.setPosition(1185,0);
    Map1wTop.setSize({448,64});
    Map1wTop.setPosition(1216,0);
    Map1wRight.setSize({32,320});
    Map1wRight.setPosition(1664,0);
    Map1wBot.setSize({192,64});
    Map1wBot.setPosition(1208,256);
    Map1wBot2.setSize({192,64});
    Map1wBot2.setPosition(1480,256);
    Map1Water1.setSize({320,110});
    Map1Water1.setPosition(1792,75);
    Map1Water2.setSize({192,240});
    Map1Water2.setPosition(1984,135);
    Map1Water3.setSize({64,180});
    Map1Water3.setPosition(2176,199);

    Tree1.setTexture(Tree);
    Tree1.setScale(3,3);
    Tree1.setPosition(1200,550);
    Tree2.setTexture(Tree);
    Tree2.setScale(3,3);
    Tree2.setPosition(1600,550);
    Bed.setTexture(bed);
    Bed.setScale(3,3);
    Bed.setPosition(1230,70);
    Books.setTexture(books);
    Books.setScale(3,3);
    Books.setPosition(1290,60);
    Books2.setTexture(books);
    Books2.setScale(3,3);
    Books2.setPosition(1520,60);
    Hair.setTexture(hair);
    Hair.setScale(3,3);
    Hair.setPosition(1356,70);
    Bench1.setTexture(bench);
    Bench1.setScale(4,4);
    Bench1.setPosition(2040,410);
    Log.setTexture(log);
    Log.setScale(4,4);
    Log.setPosition(1380,709);


    if (border.getGlobalBounds().intersects(MapRoom1.getGlobalBounds())){
        sf::View view(sf::FloatRect(1152, 0, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map1w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bed.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Hair.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bench1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Log.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wLeft.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wTop.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wRight.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water3.getGlobalBounds())
                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map1w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bed.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Hair.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bench1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Log.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wLeft.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wTop.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wRight.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water3.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map1w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bed.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Hair.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bench1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Log.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wLeft.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wTop.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wRight.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water3.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map1w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Tree2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bed.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books.getGlobalBounds())
            or border.getGlobalBounds().intersects(Books2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Hair.getGlobalBounds())
            or border.getGlobalBounds().intersects(Bench1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Log.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wLeft.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wTop.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wRight.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1wBot2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map1Water3.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}


void Inject::drawM2(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed) {
    Map2w1.setSize({830,0.01}); //
    Map2w2.setSize({128,0.01}); //
    Map2w3.setSize({0.01,580});//
    Map2w4.setSize({0.01,70}); //
    Map2w44.setSize({1088,0.01}); //
    Map2w5.setSize({0.01,450});
    Map2w55.setSize({0.01,200});
    MapRoom2.setSize({130,0.01}); //
    MapRoom2l.setSize({0.01,120});//
    MapRoom2r.setSize({0.01,120});
    Map2w1.setPosition(1152,832);
    Map2w2.setPosition(2112,832);
    Map2w3.setPosition(1152,832);
    Map2w4.setPosition(1152,1532);
    Map2w44.setPosition(1152,1599);
    Map2w5.setPosition(2240,832);
    Map2w55.setPosition(2240,1402);
    MapRoom2.setPosition(1982,832);
    MapRoom2l.setPosition(1152,1412);
    MapRoom2r.setPosition(2304,1282);
    Map2Water1.setSize({680,60});
    Map2Water1.setPosition(2000,1560);
    Map2Water2.setSize({570,60});
    Map2Water2.setPosition(2050,1490);
    if (border.getGlobalBounds().intersects(MapRoom2.getGlobalBounds())){
        sf::View view(sf::FloatRect(1152, 832, 1088, 768));
        window.setView(view);
    }
    if (border.getGlobalBounds().intersects(MapRoom2r.getGlobalBounds())){
        sf::View view(sf::FloatRect(2304, 832, 1088, 768));
        window.setView(view);
    }
    if (border.getGlobalBounds().intersects(MapRoom2l.getGlobalBounds())){
        sf::View view(sf::FloatRect(1152, 832, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map2w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water2.getGlobalBounds())
                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map2w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water2.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map2w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water2.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map2w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w44.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map2Water2.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}
void Inject::drawM3(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed) {
    Map3w1.setSize({0.01,768});
    Map3w2.setSize({1088,0.01});
    Map3w3.setSize({64,0.01});
    Map3w4.setSize({894,0.01});
    Map3w5.setSize({50,450});
    Map3w55.setSize({50,200});
    MapRoom3.setSize({130,0.01});
    MapRoom3l.setSize({0.01,120});

    //1088, 768

    Map3w1.setFillColor(sf::Color::Magenta);
    Map3w1.setPosition(3392,832);

    Map3w2.setFillColor(sf::Color::Magenta);
    Map3w2.setPosition(2304,1615);

    Map3w3.setFillColor(sf::Color::Magenta);
    Map3w3.setPosition(2304,832);

    Map3w4.setFillColor(sf::Color::Magenta);
    Map3w4.setPosition(2498,832);

    Map3w5.setFillColor(sf::Color::Magenta);
    Map3w5.setPosition(2254,832);

    Map3w55.setFillColor(sf::Color::Magenta);
    Map3w55.setPosition(2254,1402);

    MapRoom3.setFillColor(sf::Color::Yellow);
    MapRoom3.setPosition(2368,832);

    MapRoom3l.setFillColor(sf::Color::Yellow);
    MapRoom3l.setPosition(2240,1282);

    if (border.getGlobalBounds().intersects(MapRoom3.getGlobalBounds())){
        sf::View view(sf::FloatRect(2304, 832, 1088, 768));
        window.setView(view);
    }
    if (border.getGlobalBounds().intersects(MapRoom3l.getGlobalBounds())){
        sf::View view(sf::FloatRect(1152, 832, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map3w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w55.getGlobalBounds())
                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map3w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w55.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map3w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w55.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map3w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map3w55.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}

void Inject::drawM4(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed) {
    Map4w1.setSize({0.01,768});  //left
    Map4w2.setSize({1088,0.01}); //bot
    Map4w3.setSize({40,64});   //right bot
    Map4w4.setSize({40,574});  //right top
    Map4w5.setSize({128,0.01}); // top 1
    Map4w55.setSize({830,0.01}); // top 2
    MapRoom4.setSize({130,0.01}); //
    MapRoom4r.setSize({0.01,120}); //

    //1088, 768

    Map4w1.setPosition(0,832);
    Map4w2.setPosition(0,1615);
    Map4w3.setPosition(1088,1536);
    Map4w4.setPosition(1088,832);
    Map4w5.setPosition(0,832);
    Map4w55.setPosition(258,832);
    MapRoom4.setPosition(128,832);
    MapRoom4r.setPosition(1088,1406);

    if (border.getGlobalBounds().intersects(MapRoom4.getGlobalBounds())){
        sf::View view(sf::FloatRect(0, 832, 1088, 768));
        window.setView(view);
    }
    if (border.getGlobalBounds().intersects(MapRoom4r.getGlobalBounds())){
        sf::View view(sf::FloatRect(0, 832, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map4w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w55.getGlobalBounds())
                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map4w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w55.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map4w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w55.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map4w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4w55.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}

void Inject::drawM5(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed) {
    Map5w1.setSize({0.01,768}); //Left
    Map5w2.setSize({1088,0.01}); //Top
    Map5w3.setSize({0.01,768});     //Right
    Map5w5.setSize({128,50});   //Bot 1
    Map5w55.setSize({830,50}); //Bot 2
    MapRoom5.setSize({130,0.01});

    //1088, 768

    Map5w1.setPosition(0,0);
    Map5w2.setPosition(0,0);
    Map5w3.setPosition(1088,0);
    Map5w5.setPosition(0,768);
    Map5w55.setPosition(258,768);
    MapRoom5.setPosition(128,768);

    if (border.getGlobalBounds().intersects(MapRoom5.getGlobalBounds())){
        sf::View view(sf::FloatRect(0, 0, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map5w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w55.getGlobalBounds())
                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map5w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w55.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map5w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w55.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map5w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map5w55.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}

void Inject::drawM6(sf::RenderWindow &window,sf::RectangleShape& border,sf::RectangleShape& champ,int X,float speed) {
    Map6w1.setSize({0.01,768}); //Left
    Map6w2.setSize({1088,0.01}); //Top
    Map6w3.setSize({0.01,768});     //Right
    Map6w5.setSize({64,50});   //Bot 1
    Map6w55.setSize({894,50}); //Bot 2
    MapRoom6.setSize({130,0.01});

    //1088, 768

    Map6w1.setPosition(2304,0);
    Map6w2.setPosition(2304,0);
    Map6w3.setPosition(3392,0);
    Map6w5.setPosition(2304,768);
    Map6w55.setPosition(2498,768);
    MapRoom6.setPosition(2368,768);

    Map4Water1.setSize({122,485});
    Map4Water1.setPosition(970,530);

    Map4Water2.setSize({64,421});
    Map4Water2.setPosition(906,594);

    Map4Water3.setSize({64,357});
    Map4Water3.setPosition(842,658);

    Map4Water4.setSize({64,245});
    Map4Water4.setPosition(778,710);

    Map4Water5.setSize({64,190});
    Map4Water5.setPosition(714,710);

    if (border.getGlobalBounds().intersects(MapRoom6.getGlobalBounds())){
        sf::View view(sf::FloatRect(2304, 0, 1088, 768));
        window.setView(view);
    }

    if (X==1){
        if (border.getGlobalBounds().intersects(Map6w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water5.getGlobalBounds())

                ){
            champ.move(-speed,0);
        }
    }
    if (X==2){
        if (border.getGlobalBounds().intersects(Map6w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water5.getGlobalBounds())
                ){
            champ.move(0,speed);
        }
    }
    if (X==3){
        if (border.getGlobalBounds().intersects(Map6w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water5.getGlobalBounds())
                ){
            champ.move(speed,0);
        }
    }
    if (X==4){
        if (border.getGlobalBounds().intersects(Map6w1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w5.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map6w55.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water1.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water2.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water3.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water4.getGlobalBounds())
            or border.getGlobalBounds().intersects(Map4Water5.getGlobalBounds())
                ){
            champ.move(0,-speed);
        }
    }
}

Inject::Inject(sf::RenderWindow& window) {
    back.loadFromFile("../sprites/objects/back2.png");

    Tree.loadFromFile("../sprites/objects/tree.png");
    bed.loadFromFile("../sprites/objects/bed.png");
    books.loadFromFile("../sprites/objects/books.png");
    hair.loadFromFile("../sprites/objects/hair.png");
    bench.loadFromFile("../sprites/objects/bench.png");
    log.loadFromFile("../sprites/objects/log.png");
}

void Inject::draw(sf::RenderWindow &window) {
    Back.setTexture(back);
    Back.setScale(1,1);
    Back.setPosition(0,0);

    window.draw(Back);
    window.draw(Tree1);
    window.draw(Tree2);
    window.draw(Bed);
    window.draw(Books);
    window.draw(Books2);
    window.draw(Hair);
    window.draw(Bench1);
    window.draw(Log);


}
