#include "test_summery.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

void test_summery(User & Primary)
{
    sf::RenderWindow window(sf::VideoMode(1600, 960), "Test_summery", sf::Style::Close);
    window.requestFocus();
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/NewRed/Test.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End add a Background

    sf::Text username, total_tests, avg_score;
    username.setString(Primary.get_username());
    total_tests.setString(std::to_string(Primary.get_total_test()));
    avg_score.setString(std::to_string(Primary.get_avg_score()));
    cout << Primary.get_avg_score() << endl;
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

        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/PlayfairDisplay-BoldItalic.ttf");
        username.setFont(font);
        username.setFillColor(sf::Color::Black);
        username.setCharacterSize(50);
        username.setPosition(sf::Vector2f(1250, 150));
        total_tests.setFont(font);
        total_tests.setFillColor(sf::Color::Black);
        total_tests.setCharacterSize(75);
        total_tests.setPosition(sf::Vector2f(1300, 352));
        avg_score.setFont(font);
        avg_score.setFillColor(sf::Color::Black);
        avg_score.setCharacterSize(135);
        avg_score.setPosition(sf::Vector2f(1250, 620));

        window.draw(background_sprite);
        window.draw(username);
        window.draw(total_tests);
        window.draw(avg_score);
        window.display();
    }
}