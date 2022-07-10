#ifndef BIRD
#define BIRD

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "SETTINGS.h"

class Bird{

    public:
        sf::Vector2f pos  = sf::Vector2f(280,50);
        sf::Vector2f force = sf::Vector2f(0.5,0);
        sf::Vector2f vel = VECTOR_ZERO;
        float        r    = 30,
                     mass = 10;
        int          points = 1;
        bool         living = true,
                     right = true;
        sf::Sprite sprite;
        Bird(sf::Sprite& sprite):sprite(sprite){
            this->sprite.setOrigin(sf::Vector2f(25,25));
            //this->sprite.scale(-1.f,1.f);
            this->sprite.setPosition(pos);
        };

        void gravity();
        void add_force(sf::Vector2f force);
        void update_pos(sf::RenderWindow& window);
        void jump();
        void rotation_handling();
        void boundaries_collision();
        void after_death();

};


#endif