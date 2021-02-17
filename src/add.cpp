#include "../include/add.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

void add()
{
    sf::RenderWindow box(sf::VideoMode(1000, 300), "Type Something", sf::Style::None);

    // Main Loop
    while (box.isOpen())
    {
        box.requestFocus();
        sf::Event event;
        std::string str;
        while (box.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                box.close();
            }
        }
    }
}