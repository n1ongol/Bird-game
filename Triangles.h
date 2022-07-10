#ifndef TRIANGLES
#define TRIANGLES

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bird.h"
#include <math.h>
#include <vector>
#include "SETTINGS.h"

class Triangles{

    public:
        sf::Vector2f spike_pos;
        Bird* bird;
        
        Triangles(Bird* bird):bird(bird){
            this->spike_pos.y = rand()%500+50;
        };
        
        void generate(sf::VertexArray&);
        void update(bool& bounce, int& points, std::vector<Triangles*>& triangles);


};

#endif