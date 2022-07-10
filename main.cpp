#include <SFML/Graphics.hpp>
#include <iostream>
#include "SETTINGS.h"
#include "bird.h"
#include "Triangles.h"
#include <random>
#include <time.h>



int main(){

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "GravitySimulator",sf::Style::Default, settings);
    sf::RectangleShape background(sf::Vector2f(350,600));
    background.move(sf::Vector2f(225,0));

    sf::Font font;
    font.loadFromFile("RobotoCondensed-Light.ttf");
    sf::Text text;
    text.setFont(font);
    text.setPosition(sf::Vector2f(395,500));
    text.setColor(sf::Color::Black);

    sf::Sprite sprite;
    sf::Texture bird_text;
    bird_text.loadFromFile("bird.png");
    sprite.setTexture(bird_text);

    Bird* bird = new Bird(sprite);
    bool bounce = bird->right;

    std::vector<Triangles*> triangles;
    triangles.push_back(new Triangles(bird));

    while(window.isOpen()){
        text.setString(std::to_string(bird->points));
        sf::VertexArray spikes(sf::Triangles);
        //std::cout << triangles[0]->spike_pos.x << " " << triangles[0]->spike_pos.y << std::endl;
        //std::cout << bird->right << std::endl;
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
                if((event.key.code == sf::Keyboard::Space) && bird->living)
                    bird->jump();

            }
        }
        bird->gravity();
        bird->boundaries_collision();
        bird->after_death();
        //bird.rotation_handling();
        
        
        window.clear();
        for(int t = 0; t<triangles.size();t++){
            triangles[t]->update(bounce,bird->points,triangles);
            triangles[t]->generate(spikes);
        }
        window.draw(background);
        window.draw(spikes);
        window.draw(text);
        bird->update_pos(window);
        
          
        window.display();
    }
    return 0;

}