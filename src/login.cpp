#include "../include/login.hpp"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

bool login()
{
    sf::RenderWindow window(sf::VideoMode(1600, 960), "login", sf::Style::Close);
    window.requestFocus();
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/NewRed/Login.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End add a Background
    sf::RectangleShape rec1, rec2;
    rec1.setSize(sf::Vector2f(480, 82));
    rec1.setPosition(sf::Vector2f(560, 330));
    rec1.setFillColor(sf::Color::Blue);
    rec2.setSize(sf::Vector2f(480, 82));
    rec2.setPosition(sf::Vector2f(560, 490));
    rec2.setFillColor(sf::Color::Blue);

    string input = "", tmp_user = "", tmp_pass = "", username = "", password = "";
    sf::Text user, pass;
    int cur_box = 1;
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
            // Choose UserName Or Password
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (rec1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cur_box = 0;
                }
                else if (rec2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cur_box = 1;
                }
            }
            // End Choose UserName Or Password
            // Hanlding Entering Text
            if (event.type == sf::Event::TextEntered)
            {                                   // Handle ASCII characters only Except Enter:13 & Backsapce:8
                if (event.text.unicode <= 128   // Be an ascii char
                    && event.text.unicode != 8  // Backspace
                    && event.text.unicode != 13 // Enter
                    && event.text.unicode != 59 // semicolon :: used in file handling
                )
                {
                    (cur_box ? password : username) += event.text.unicode;
                    (cur_box ? pass : user).setString(cur_box ? password : username);
                    cout << "got input! : " << (cur_box ? password : username) << " -> " << (cur_box ? password : username).length() << endl;
                    // if (cur_box == 0) // UserName
                    // {
                    //     username += event.text.unicode;
                    //     text.setString(username);
                    //     cout << "got input!(username) : " << input << " -> " << input.length() << endl;
                    // }
                    // if (cur_box == 1) // Password
                    // {
                    //     password += event.text.unicode;
                    //     text.setString(password);
                    //     cout << "got input!(password) : " << input << " -> " << input.length() << endl;
                    // }
                }
                // Handling Enter
                if (event.text.unicode == 13 && input.length() != 0 && input.find(':') != string::npos)
                {
                    cout << "enter!!" << endl;
                }
                // Handling Backsapce
                if (event.text.unicode == 8)
                {
                    (cur_box ? pass : user).setString(cur_box ? password : username);
                    (cur_box ? password : username) = cur_box ? tmp_pass : tmp_user;
                    // cout << "Backspace" << endl;
                }
            }
        }
        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/Poppins-Regular.ttf");
        user.setFont(font);
        user.setFillColor(sf::Color::Black);
        user.setCharacterSize(22);
        user.setPosition(sf::Vector2f(585, 355));
        pass.setFont(font);
        pass.setFillColor(sf::Color::Black);
        pass.setCharacterSize(22);
        pass.setPosition(sf::Vector2f(585, 515));
        tmp_user = username.substr(0, username.length() - 1); // Keeping Last input for usage in backsapce
        tmp_pass = password.substr(0, password.length() - 1); // Keeping Last input for usage in backsapce

        window.draw(background_sprite);
        // window.draw(rec1);
        // window.draw(rec2);
        window.draw(user);
        window.draw(pass);
        window.display();
    }
}