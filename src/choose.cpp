#include "../include/choose.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

bool choose()
{
    sf::RenderWindow window(sf::VideoMode(1600, 960), "Choose", sf::Style::Close);
    window.requestFocus();
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/NewRed/Select.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End add a Background

    // Add Learn Icon
    sf::Texture learn_texture, learn_texture_hover;
    if (!learn_texture.loadFromFile("../assets/images/NewRed/Learn_1.png"))
        cout << "Error On Loading learn Image" << endl;
    if (!learn_texture_hover.loadFromFile("../assets/images/NewRed/Learn-hover.png"))
        cout << "Error On Loading learn-hover Image" << endl;
    sf::Sprite learn_sprite;
    learn_sprite.setTexture(learn_texture);
    learn_sprite.setPosition(400, 400);
    // End add Learn Icon
    // Add Exam Icon
    sf::Texture Exam_texture, Exam_texture_hover;
    if (!Exam_texture.loadFromFile("../assets/images/NewRed/Exam_1.png"))
        cout << "Error On Loading Exam Image" << endl;
    if (!Exam_texture_hover.loadFromFile("../assets/images/NewRed/Exam-hover.png"))
        cout << "Error On Loading Exam-hover Image" << endl;
    sf::Sprite Exam_sprite;
    Exam_sprite.setTexture(Exam_texture);
    Exam_sprite.setPosition(870, 400);
    // End add Learn Icon

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
                return -4;
            }
            // Mouse Click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Click on Learn
                if (learn_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << " Learn" << endl;
                    return 0;
                }
                // Click on Exam
                if (Exam_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << " Exam" << endl;
                    return 1;
                }
            }
            // Mouse Move
            if (event.type == sf::Event::MouseMoved)
            {
                // Exam Icon
                if (Exam_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    Exam_sprite.setTexture(Exam_texture_hover);
                }
                else
                {
                    Exam_sprite.setTexture(Exam_texture);
                }
                // learn Icon
                if (learn_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    learn_sprite.setTexture(learn_texture_hover);
                }
                else
                {
                    learn_sprite.setTexture(learn_texture);
                }
            }
        }
        window.draw(background_sprite);
        window.draw(learn_sprite);
        window.draw(Exam_sprite);
        window.display();
    }
}