#include "real_test.hpp"
#include "../include/word.hpp"
#include <iostream>
#include <string>
#include <deque>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::deque;
using std::endl;
using std::string;

void real_test(User &Primary)
{
    sf::RenderWindow window(sf::VideoMode(1600, 960), "Do The Test", sf::Style::Close);
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/NewRed/Exam.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background

    while (window.isOpen())
    {
        sf::Event event;
        std::string str;
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