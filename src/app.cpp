#include "../include/app.hpp"
#include "../include/add.hpp"
#include "../include/word.hpp"
#include "../include/file.hpp"

#include <iostream>
#include <deque>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define window_x 1600
#define window_y 960
#define add_icon_x 1450
#define add_icon_y 820

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
    // Add ADD-Icon
    sf::Texture add_texture;
    if (!add_texture.loadFromFile("../assets/icons/add.png"))
        cerr << "Error On Loading ADD-Icon" << endl;
    sf::Sprite add_sprite;
    add_sprite.setTexture(add_texture);
    add_sprite.setPosition(sf::Vector2f(add_icon_x, add_icon_y));
    // Add add-icon : Hovered
    sf::Texture add_texture_hovered;
    if (!add_texture_hovered.loadFromFile("../assets/icons/add-hover.png"))
        cerr << "Error On Loading Add-hover" << endl;
    //End Of Adding ADD-Icon

    array<deque<Word>, 7> arr;
    read_file(arr);

    Word word;
    word = arr[0][0];
    sf::Text word_text, meaning_text;
    word_text.setString(word.get_word());
    meaning_text.setString(word.get_meaning());
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
            //  Mouse Moved
            if (event.type == sf::Event::MouseMoved)
            {
                if (add_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    add_sprite.setTexture(add_texture_hovered);
                }
                else
                {
                    add_sprite.setTexture(add_texture);
                }
            }
            // Mouse CLICK
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (add_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "Add Click!" << endl;
                    add(arr[0], Theme_mode[curr_mod], Theme_color[curr_color]);
                }
            }
        }

        window.draw(background_sprite);

        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/Poppins-Bold.ttf");
        word_text.setFont(font);
        meaning_text.setFont(font);
        word_text.setFillColor(sf::Color::Black);
        meaning_text.setFillColor(sf::Color::Black);
        word_text.setCharacterSize(40);
        meaning_text.setCharacterSize(40);
        word_text.setPosition(sf::Vector2f(260, 450));
        meaning_text.setPosition(sf::Vector2f(960, 450));
        window.draw(word_text);
        window.draw(meaning_text);
        window.draw(add_sprite);
        window.display();
    }
    write_file(arr);
}