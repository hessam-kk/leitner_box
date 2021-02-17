#include "../include/add.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

void add(const string &cur_mode, const string &cur_col)
{
    sf::RenderWindow box(sf::VideoMode(800, 300), "Type Something", sf::Style::None);

    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/addbox-" + cur_col + cur_mode + ".png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background

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
        box.draw(background_sprite);
        box.display();
    }
}