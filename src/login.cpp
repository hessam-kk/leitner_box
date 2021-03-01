#include "login.hpp"
#include "file.hpp"
#include "user.hpp"
#include "sha256.h"

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;
using std::string;

bool login(User &primary)
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
    // Add Enter Icon
    sf::Texture Enter_texture, Enter_texture_hover;
    if (!Enter_texture.loadFromFile("../assets/images/NewRed/Enter.png"))
        cout << "Error On Loading Enter Image" << endl;
    if (!Enter_texture_hover.loadFromFile("../assets/images/NewRed/Enter-hover.png"))
        cout << "Error On Loading Enter-hover Image" << endl;
    sf::Sprite Enter_sprite;
    Enter_sprite.setTexture(Enter_texture);
    Enter_sprite.setPosition(500, 600);
    // End add Enter Icon
    // Add Sign Icon
    sf::Texture Sign_texture, Sign_texture_hover;
    if (!Sign_texture.loadFromFile("../assets/images/NewRed/Sign.png"))
        cout << "Error On Loading Sign Image" << endl;
    if (!Sign_texture_hover.loadFromFile("../assets/images/NewRed/Sign-hover.png"))
        cout << "Error On Loading Sign-hover Image" << endl;
    sf::Sprite Sign_sprite;
    Sign_sprite.setTexture(Sign_texture);
    Sign_sprite.setPosition(810, 600);
    // End add Sign Icon
    // Password And UserName Boxes
    sf::RectangleShape rec1, rec2;
    rec1.setSize(sf::Vector2f(480, 82));
    rec1.setPosition(560, 330);
    rec1.setFillColor(sf::Color::Blue);
    rec2.setSize(sf::Vector2f(480, 82));
    rec2.setPosition(560, 490);
    rec2.setFillColor(sf::Color::Blue);

    string input = "", tmp_user = "", tmp_pass = "", username = "", password = "";
    sf::Text user, pass;
    int cur_box = 0;
    User my_user;
    SHA256 sha256; // To Store Password Crypted

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
            // Mouse Click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Choose UserName Or Password
                if (rec1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    cur_box = 0;
                else if (rec2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    cur_box = 1;
                // End Choose UserName Or Password

                // Click On ENTER
                if (Enter_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "Enter User:" << username << " Pass:" << password << endl;
                    my_user = read_user(username);
                    cout << "HI  " << my_user.get_username() << endl;
                    if (my_user.get_username() == "404")
                    {
                        cout << "no user available" << endl;
                    }
                    else
                    {
                        if (password == my_user.get_password())
                        {
                            cout << "Login Successful!!" << endl;
                            primary = my_user;
                            return 1;
                        }
                        else
                        {
                            cout << "Wrong Password!!" << endl;
                        }
                    }
                } // End Click On Enter
                // Click On Sign in
                if (Sign_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    // Search for Username account
                    my_user = read_user(username);
                    if (my_user.get_username() == "404")
                    {
                        my_user = User(username, password);
                        write_user(my_user);
                        cout << "signed UP" << endl;
                    }
                    else
                    {
                        cout << "duplicated" << endl;
                    }
                }
                // End Click On Sign in
            }
            // End Choose UserName Or Password
            // End Mouse Click
            // Mouse Move
            if (event.type == sf::Event::MouseMoved)
            {
                // Enter Icon
                if (Enter_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    Enter_sprite.setTexture(Enter_texture_hover);
                }
                else
                {
                    Enter_sprite.setTexture(Enter_texture);
                }
                // Sign Icon
                if (Sign_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    Sign_sprite.setTexture(Sign_texture_hover);
                }
                else
                {
                    Sign_sprite.setTexture(Sign_texture);
                }
            } // End Mouse Move

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
                }
                // Handling Enter
                if (event.text.unicode == 13 && input.length() != 0 && input.find(':') != string::npos)
                {
                    cout << "enter!!" << endl;
                }
                // Handling Backsapce
                if (event.text.unicode == 8)
                {
                    (cur_box ? password : username) = cur_box ? tmp_pass : tmp_user;
                    (cur_box ? pass : user).setString(cur_box ? password : username);
                    // cout << "Backspace" << endl;
                }
            }
            // End Handling Entring Text
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
        window.draw(Enter_sprite);
        window.draw(Sign_sprite);
        window.display();
    }
    return 1;
}

// TODO show Star for pass