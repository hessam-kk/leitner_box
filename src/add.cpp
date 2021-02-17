#include "../include/add.hpp"
#include "../include/word.hpp"
#include <iostream>
#include <string>
#include <deque>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;
using std::deque;

void add(deque<Word> & deq, const string &cur_mode, const string &cur_col)
{
    sf::RenderWindow box(sf::VideoMode(800, 300), "Type Something", sf::Style::None);

    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/addbox-" + cur_col + cur_mode + ".png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background
    string input = "", tmp = "";
    sf::Text text;
    text.setString(input);
    Word tmp_word;

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
            // Hanlding Entering Text
            if (event.type == sf::Event::TextEntered)
            {                                    // Handle ASCII characters only Except Enter:13 & Backsapce:8
                if (event.text.unicode <= 128    // Be an ascii char
                    && event.text.unicode != 8   // Backspace
                    && event.text.unicode != 13  // Enter
                    && event.text.unicode != 59) // semicolon :: used in file handling
                {
                    input += event.text.unicode;
                    text.setString(input);
                    cout << "got input! : " << input << " -> " << input.length() << endl;
                }
                // Handling Enter
                if (event.text.unicode == 13 && input.length() != 0 && input.find(':') != string::npos)
                {
                    tmp_word.set_word(input.substr(0, input.find(':')));
                    tmp_word.set_meaning(input.substr(input.find(':')+1));
                    tmp_word.set_day(0);
                    deq.push_back(tmp_word);
                    cout << "enter!!" << endl;
                    box.close();
                }
                // Handling Backsapce
                if (event.text.unicode == 8)
                {
                    text.setString(tmp);
                    input = tmp;
                    // cout << "Backspace" << endl;
                }
            } // End Of Text Handling
        }
        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/Poppins-Regular.ttf");
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(22);
        text.setPosition(sf::Vector2f(160, 175));
        tmp = input.substr(0, input.length() - 1); // Keeping Last input for usage in backsapce
        box.draw(background_sprite);
        box.draw(text);

        box.display();
    }
}