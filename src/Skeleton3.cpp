//
// Created by dawid on 27.05.2024.
//

#include <random>
#include "Skeleton3.h"
#include "fmt/core.h"

Skeleton3::Skeleton3(sf::Texture *texture, sf::Clock clock){
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(5, 30);
    row=0;
    speed=distribution(generator)*0.2;
    skeleton.setSize(sf::Vector2f(150, 150));
    skeleton.setTexture(texture);
    skeleton.setPosition(1180, 1100);

    skeletonBor.setSize({40,64});
    skeletonBor.setFillColor(sf::Color::White);

    std::uniform_int_distribution<int> distributionX(100, 900);
    fmt::println("{}",distributionX(generator));
    std::uniform_int_distribution<int> distributionY(832, 1000);
    fmt::println("{}",distributionY(generator));
    skeleton.setPosition(distributionX(generator), distributionY(generator));
    Animation animation(texture);
    Skeleton3::an=animation;

};

void Skeleton3::draw(sf::RenderWindow &window) {
    window.draw(skeleton);
}
void Skeleton3::move(sf::RenderWindow &window, sf::RectangleShape shape2) {
    x=(skeletonBor.getPosition().x-shape2.getPosition().x);
    y=(skeletonBor.getPosition().y-shape2.getPosition().y);


    if (SkeletonHP<=0){
        an.skeletonDead(4,clock1);
        skeleton.setTextureRect(an.uvRect6);

    } else {
        if (x <= 300 and  x>=-300 and y <= 300 and y>=-300) {
            if (skeletonBor.getPosition().x > shape2.getPosition().x) {
                moveOn.x -= speed;
                an.skeleton(5, clock1);
                skeleton.setTextureRect(an.uvRect2);
            }
            if (skeletonBor.getPosition().x < shape2.getPosition().x) {
                moveOn.x += speed;
                an.skeleton(1, clock1);
                skeleton.setTextureRect(an.uvRect2);
            }
            if (skeletonBor.getPosition().y > shape2.getPosition().y) {
                moveOn.y -= speed;
                an.skeleton(1, clock1);
                skeleton.setTextureRect(an.uvRect2);
            }
            if (skeletonBor.getPosition().y < shape2.getPosition().y) {
                moveOn.y += speed;
                an.skeleton(5, clock1);
                skeleton.setTextureRect(an.uvRect2);
            }
            if (skeletonBor.getGlobalBounds().intersects(shape2.getGlobalBounds())) {
                moveOn = {0, 0};

                an.skeletonAttack(2, clock1);
                skeleton.setTextureRect(an.uvRect3);
            }
            // fmt::println("{}",SkeletonHP);
            skeleton.move(moveOn);
            moveOn = {0, 0};

            skeletonBor.setPosition(skeleton.getPosition().x + 58, skeleton.getPosition().y + 70);
        } else {
            if (moveOn.x == 0 and moveOn.y == 0) {
                an.skeleton(0, clock1);
                skeleton.setTextureRect(an.uvRect2);
            }
        }
    }
}

Skeleton3::Skeleton3() {

}