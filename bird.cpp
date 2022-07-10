#include "bird.h"
#include <iostream>

void Bird::gravity(){
    this->force += GRAVITY;
}

void Bird::add_force(sf::Vector2f force){
    this->force += force;
}

void Bird::update_pos(sf::RenderWindow& window){
    //Object pos
    this->vel += this->force / this->mass;
    this->pos += this->vel;
    this->force = VECTOR_ZERO;
    
    //Sprite pos
    
    this->sprite.move(this->vel);
    
    window.draw(sprite);    

}

void Bird::jump(){
    this->vel.y = 0;
    this->add_force(JUMP_FORCE);
}

void Bird::rotation_handling(){
    ///NIE DZIALA
    this->sprite.rotate(0);
    this->sprite.rotate(this->vel.y);
}

void Bird::boundaries_collision(){

    if(this->living){
        if(this->pos.x >= 550 || this->pos.x <= 250){
            if(this->vel.x < 0)
                this->vel.x -= 0.001;
            else
                this->vel.x += 0.001;
            this->vel.x *= -1;
            this->sprite.scale(-1.f,1.f);
            this->right = !this->right;
        }
        if(this->pos.y >= 600 || this->pos.y <= 0)
            this->living = false;
    }
}

void Bird::after_death(){
    if(!this->living){
        this->vel *= 0.9999f;
        this->sprite.rotate(5.0);
    }
}