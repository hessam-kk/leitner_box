#include "../include/app.hpp"

#include <iostream>
#include <deque>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define window_x 1600
#define window_y 960

using namespace std;

void app()
{
    string Theme_mode[2] = {"light", "dark"};
    string Theme_color[4] = {"blue", "red", "green", "yellow"};
    int curr_mod = 0, curr_color = 0; 
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Leitner Box", sf::Style::Close); //size:  (9  in  16)  * 60
    window.requestFocus();
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/background-" + Theme_color[curr_color] + Theme_mode[curr_mod] + ".png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background

    // Main Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close Window
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
        }
        window.draw(background_sprite);
        window.display();
    }
}