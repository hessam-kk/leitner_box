#include "test_summery.hpp"
#include "real_test.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

void test_summery(User &Primary)
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
    // Add Start Icon
    sf::Texture Start_texture, Start_texture_hover;
    if (!Start_texture.loadFromFile("../assets/images/NewRed/Start.png"))
        cout << "Error On Loading Start Image" << endl;
    if (!Start_texture_hover.loadFromFile("../assets/images/NewRed/Start-hover.png"))
        cout << "Error On Loading Start-hover Image" << endl;
    sf::Sprite Start_sprite;
    Start_sprite.setTexture(Start_texture);
    Start_sprite.setPosition(235, 150);
    // End add Enter Icon
    sf::Text username, total_tests, avg_score, last_score, corrects, wrongs, total_questions;
    username.setString(Primary.get_username());

    while (window.isOpen())
    {
        total_tests.setString(std::to_string(Primary.get_total_test()));
        avg_score.setString(std::to_string(Primary.get_total_score()));
        last_score.setString(std::to_string(Primary.last_one.score));
        corrects.setString(std::to_string(Primary.last_one.corrects));
        wrongs.setString(std::to_string(Primary.last_one.wrongs));
        total_questions.setString(std::to_string(Primary.last_one.total_questions));
        sf::Event event;
        std::string str;
        while (window.pollEvent(event))
        {
            // Close Window
            if (event.type == sf::Event::EventType::Closed)
            {
                write_user(Primary);
                window.close();
            }
            // Mouse Move
            if (event.type == sf::Event::MouseMoved)
            {
                // Enter Icon
                if (Start_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    Start_sprite.setTexture(Start_texture_hover);
                }
                else
                {
                    Start_sprite.setTexture(Start_texture);
                }
            }
            // Mouse Click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Enter The Test
                if (Start_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    real_test(Primary);
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

        last_score.setFont(font);
        last_score.setFillColor(sf::Color::Black);
        last_score.setCharacterSize(50);
        last_score.setPosition(sf::Vector2f(260, 540));

        corrects.setFont(font);
        corrects.setFillColor(sf::Color::Black);
        corrects.setCharacterSize(45);
        corrects.setPosition(sf::Vector2f(850, 540));

        wrongs.setFont(font);
        wrongs.setFillColor(sf::Color::Black);
        wrongs.setCharacterSize(45);
        wrongs.setPosition(sf::Vector2f(850, 590));

        total_questions.setFont(font);
        total_questions.setFillColor(sf::Color::Black);
        total_questions.setCharacterSize(45);
        total_questions.setPosition(sf::Vector2f(940, 640));

        // last_score, corrects, wrongs, total_questions, percantage;
        window.draw(background_sprite);
        window.draw(username);
        window.draw(total_tests);
        window.draw(avg_score);
        window.draw(last_score);
        window.draw(corrects);
        window.draw(wrongs);
        window.draw(total_questions);
        window.draw(Start_sprite);
        window.display();
    }
}