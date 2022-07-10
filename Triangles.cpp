#include "Triangles.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bird.h"
#include <math.h>
#include "SETTINGS.h"

void Triangles::generate(sf::VertexArray& spikes){

    /*
            this->bird = bird;
            if(bird->right)
                spike_pos.x = 550.0f;
            else
                spike_pos.x = 250.0f;
            spike_pos.y = rand()%500+50;
    */

    sf::Vertex w1,w2,w3;

    if(this->bird->right)
        this->spike_pos.x = 550.0f;
    else
        this->spike_pos.x = 250.0f;

    w1.position = sf::Vector2f(this->spike_pos);
    w2.position = sf::Vector2f(this->spike_pos.x + this->bird->sprite.getScale().x*25,this->spike_pos.y-28.9);
    //w2.position = sf::Vector2f(this->spike_pos.x+25,this->spike_pos.y-28.9);
    //w3.position = sf::Vector2f(this->spike_pos.x+25,this->spike_pos.y+28.9);
    w3.position = sf::Vector2f(this->spike_pos.x + this->bird->sprite.getScale().x*25,this->spike_pos.y+28.9);

    w1.color = sf::Color::Black;
    w2.color = sf::Color::Black;
    w3.color = sf::Color::Black;

    spikes.append(w1);
    spikes.append(w2);
    spikes.append(w3);

}

void Triangles::update(bool& bounce, int& points, std::vector<Triangles*>& triangles){

    if(bounce != this->bird->right){
        this->spike_pos.y = rand()%500+50;  
        bounce = this->bird->right;
        points++;
        if(points%5==0)
            triangles.push_back(new Triangles(this->bird));
    }
}