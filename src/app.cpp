#include "../include/app.hpp"
#include "../include/add.hpp"
#include "../include/word.hpp"
#include "../include/file.hpp"

#include <iostream>
#include <deque>
#include <array>
#include <stdexcept>
#include <unistd.h>
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
    string Theme_color[6] = {"blue", "red", "green", "yellow", "purple", "pink"};
    int curr_mod = 1, curr_color = 3;
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Leitner Box", sf::Style::Close); //size:  (9  in  16)  * 60
    window.requestFocus();
    // Add Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/back.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background
    // Add ADD-Icon
    sf::Texture add_texture;
    if (!add_texture.loadFromFile("../assets/icons/dark/" + Theme_color[curr_color] + "/add.png"))
        cerr << "Error On Loading ADD-Icon" << endl;
    sf::Sprite add_sprite;
    add_sprite.setTexture(add_texture);
    add_sprite.setPosition(sf::Vector2f(add_icon_x, add_icon_y));
    // Add add-icon : Hovered
    sf::Texture add_texture_hovered;
    if (!add_texture_hovered.loadFromFile("../assets/icons/dark/" + Theme_color[curr_color] + "/add-hover.png"))
        cerr << "Error On Loading Add-hover" << endl;
    //End Of Adding ADD-Icon

    // Add ok-Icon
    sf::Texture ok_texture;
    if (!ok_texture.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + "/ok.png"))
        cerr << "Error On Loading ok-Icon" << endl;
    sf::Sprite ok_sprite;
    ok_sprite.setTexture(ok_texture);
    // Add ok-icon : Hovered
    sf::Texture ok_texture_hovered;
    if (!ok_texture_hovered.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + "/ok-hover.png"))
        cerr << "Error On Loading ok-hover" << endl;
    ok_sprite.setPosition(sf::Vector2f(690, 213));
    //End Of Adding ok-Icon
    // Add no-Icon
    sf::Texture no_texture;
    if (!no_texture.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + "/no.png"))
        cerr << "Error On Loading no-Icon" << endl;
    sf::Sprite no_sprite;
    no_sprite.setTexture(no_texture);
    // Add no-icon : Hovered
    sf::Texture no_texture_hovered;
    if (!no_texture_hovered.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + "/no-hover.png"))
        cerr << "Error On Loading no-hover" << endl;
    no_sprite.setPosition(sf::Vector2f(690, 213 + 142));
    // Add next-Icon
    sf::Texture next_texture;
    if (!next_texture.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/next.png"))
        cerr << "Error On Loading next-Icon" << endl;
    sf::Sprite next_sprite;
    next_sprite.setTexture(next_texture);
    // Add next-icon : Hovered
    sf::Texture next_texture_hovered;
    if (!next_texture_hovered.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/next-hover.png"))
        cerr << "Error On Loading next-hover" << endl;
    next_sprite.setPosition(sf::Vector2f(690, 213 + 100 + 180));
    //End Of Adding next-Icon
    // Add next-Icon
    sf::Texture next_day_texture;
    if (!next_day_texture.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/day.png"))
        cerr << "Error On Loading next_day-Icon" << endl;
    sf::Sprite next_day_sprite;
    next_day_sprite.setTexture(next_day_texture);
    // Add next_day-icon : Hovered
    sf::Texture next_day_texture_hovered;
    if (!next_day_texture_hovered.loadFromFile("../assets/icons/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/day-hover.png"))
        cerr << "Error On Loading next_day-hover" << endl;
    next_day_sprite.setPosition(sf::Vector2f(690, 213 + 142 + 100 + 180));
    //End Of Adding next_day-Icon
    // theme-Icons
    sf::Texture blue_texture;
    if (!blue_texture.loadFromFile("../assets/icons/blue.png"))
        cerr << "Error On Loading blue-Icon" << endl;
    sf::Sprite blue_sprite;
    blue_sprite.setTexture(blue_texture);
    blue_sprite.setPosition(sf::Vector2f(1150, 25));
    // -------------------------------------
    sf::Texture red_texture;
    if (!red_texture.loadFromFile("../assets/icons/red.png"))
        cerr << "Error On Loading red-Icon" << endl;
    sf::Sprite red_sprite;
    red_sprite.setTexture(red_texture);
    red_sprite.setPosition(sf::Vector2f(1150 + 73, 25));
    // -------------------------------------
    sf::Texture green_texture;
    if (!green_texture.loadFromFile("../assets/icons/green.png"))
        cerr << "Error On Loading green-Icon" << endl;
    sf::Sprite green_sprite;
    green_sprite.setTexture(green_texture);
    green_sprite.setPosition(sf::Vector2f(1150 + 73 * 2, 25));
    // -------------------------------------
    sf::Texture purple_texture;
    if (!purple_texture.loadFromFile("../assets/icons/purple.png"))
        cerr << "Error On Loading purple-Icon" << endl;
    sf::Sprite purple_sprite;
    purple_sprite.setTexture(purple_texture);
    purple_sprite.setPosition(sf::Vector2f(1150 + 73 * 3, 25));
    // -------------------------------------
    sf::Texture yellow_texture;
    if (!yellow_texture.loadFromFile("../assets/icons/yellow.png"))
        cerr << "Error On Loading yellow-Icon" << endl;
    sf::Sprite yellow_sprite;
    yellow_sprite.setTexture(yellow_texture);
    yellow_sprite.setPosition(sf::Vector2f(1150 + 73 * 4, 25));
    // -------------------------------------
    sf::Texture pink_texture;
    if (!pink_texture.loadFromFile("../assets/icons/pink.png"))
        cerr << "Error On Loading pink-Icon" << endl;
    sf::Sprite pink_sprite;
    pink_sprite.setTexture(pink_texture);
    pink_sprite.setPosition(sf::Vector2f(1150 + 73 * 5, 25));
    // -------------------------------------
    sf::Texture dark_texture;
    if (!dark_texture.loadFromFile("../assets/icons/dark.png"))
        cerr << "Error On Loading dark-Icon" << endl;
    sf::Sprite dark_sprite;
    dark_sprite.setTexture(dark_texture);
    dark_sprite.setPosition(sf::Vector2f(1150 + 73 * 4, 100));
    // -------------------------------------
    sf::Texture light_texture;
    if (!light_texture.loadFromFile("../assets/icons/light.png"))
        cerr << "Error On Loading light-Icon" << endl;
    sf::Sprite light_sprite;
    light_sprite.setTexture(light_texture);
    light_sprite.setPosition(sf::Vector2f(1150 + 73 * 5, 100));
    // -------------------------------------
    // end theme-Icons

    array<deque<Word>, 7> arr;
    read_file(arr);
    Word word;

    sf::Text word_text, meaning_text, cur_day_text;
    unsigned short int cur_day = 0;
    bool clicked = false;
    string prev_click = "";
    // Main Loop
    while (window.isOpen())
    {
        window.draw(background_sprite);
        // Top Left Status
        cur_day_text.setString("Today: " + to_string(cur_day + 1));
        // Find First Word
        if (!arr[cur_day].empty())
        {
            word = arr.at(cur_day).front();
            word_text.setString(word.get_word());
            meaning_text.setString(word.get_meaning());
        }
        else // Day Has No Word
        {
            word_text.setString("NoWordForToday");
            meaning_text.setString("");
        }

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
                // ADD Icon
                if (add_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    add_sprite.setTexture(add_texture_hovered);
                }
                else
                {
                    add_sprite.setTexture(add_texture);
                }
                // OK Icon
                if (ok_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    ok_sprite.setTexture(ok_texture_hovered);
                }
                else
                {
                    ok_sprite.setTexture(ok_texture);
                }
                // NO Icon
                if (no_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    no_sprite.setTexture(no_texture_hovered);
                }
                else
                {
                    no_sprite.setTexture(no_texture);
                }
                // Next Word Icon
                if (next_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    next_sprite.setTexture(next_texture_hovered);
                }
                else
                {
                    next_sprite.setTexture(next_texture);
                }
                // Next Day Icon
                if (next_day_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    next_day_sprite.setTexture(next_day_texture_hovered);
                }
                else
                {
                    next_day_sprite.setTexture(next_day_texture);
                }
            } // End Hover
            // Mouse CLICK
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Click on ADD Button
                if (add_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    add(arr[0], Theme_mode[curr_mod], Theme_color[curr_color]);
                    cout << "Add Click!" << endl;
                }
                // Click on OK Button
                if (ok_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (static_cast<string>(word_text.getString()) != "NoWordForToday")
                    {
                        prev_click = "ok";
                        clicked = true;
                    }
                    cout << "ok Click!" << endl;
                }
                // Click on NO Button
                if (no_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (static_cast<string>(word_text.getString()) != "NoWordForToday")
                    {

                        prev_click = "no";
                        clicked = true;
                    }
                    cout << "no Click!" << endl;
                }
                // Click on Next Button
                if (next_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (static_cast<string>(word_text.getString()) != "NoWordForToday")
                    {
                        // Clicked on OK and want to go to next word
                        if (prev_click == "ok")
                        {
                            if (cur_day == 6)
                            {
                                arr[cur_day].pop_front();
                                prev_click = "";
                            }
                            else
                            {
                                arr[cur_day + 1].push_back(word);
                                arr.at(cur_day).pop_front();
                                prev_click = "";
                            }
                        }
                        // Clicked on NO and want to go to next word
                        else if (prev_click == "no")
                        {
                            arr.at(0).push_back(word);
                            arr.at(cur_day).pop_front();
                            prev_click = "";
                        }
                        // Nothing clicked and want to skip the word
                        else
                        {
                            arr.at(cur_day).push_back(word);
                            arr.at(cur_day).pop_front();
                            prev_click = "";
                        }
                    }
                    clicked = false;
                    cout << "next Click!" << endl;
                } // End Click on Next Button
                // Click on Next-day Button
                if (next_day_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (cur_day < 6)
                    {
                        cur_day++;
                        cout << "day: " << cur_day << endl;
                    }
                    else
                    {
                        cur_day = 0;
                        cout << "day: " << cur_day << endl;
                    }
                    clicked = false;
                    cout << "next day Click!" << endl;
                } // End Click on Next-day Button
                  // string Theme_color[6] = {"blue", "red", "green", "yellow", "purple", "pink"};
                if (blue_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: blue" << endl;
                    curr_color = 0;
                }
                if (red_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: red" << endl;
                    curr_color = 1;
                }
                if (green_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: green" << endl;
                    curr_color = 2;
                }
                if (yellow_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: yellow" << endl;
                    curr_color = 3;
                }
                if (purple_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: purple" << endl;
                    curr_color = 4;
                }
                if (pink_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: pink" << endl;
                    curr_color = 5;
                }
                if (light_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: light" << endl;
                    curr_mod = 0;
                }
                if (dark_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "theme: dark" << endl;
                    curr_mod = 1;
                }
                if (!background_texture.loadFromFile("../assets/images/" + Theme_mode[curr_mod] + '/' + Theme_color[curr_color] + "/back.png"))
                    cout << "Error On Loading BackGround Image" << endl;
                background_sprite.setTexture(background_texture);
            }
        }
        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/Poppins-Bold.ttf");
        word_text.setFont(font);
        meaning_text.setFont(font);
        cur_day_text.setFont(font);
        if (curr_mod == 0)
        {
            word_text.setFillColor(sf::Color::Black);
            meaning_text.setFillColor(sf::Color::Black);
            cur_day_text.setFillColor(sf::Color::Black);
        }
        else
        {
            word_text.setFillColor(sf::Color::White);
            meaning_text.setFillColor(sf::Color::White);
            cur_day_text.setFillColor(sf::Color::White);
        }
        word_text.setCharacterSize(40);
        meaning_text.setCharacterSize(40);
        cur_day_text.setCharacterSize(40);
        word_text.setPosition(sf::Vector2f(260, 450));
        meaning_text.setPosition(sf::Vector2f(960, 450));
        cur_day_text.setPosition(sf::Vector2f(50, 25));
        window.draw(ok_sprite);
        window.draw(no_sprite);
        window.draw(word_text);
        window.draw(add_sprite);
        window.draw(next_sprite);
        window.draw(next_day_sprite);
        window.draw(cur_day_text);
        window.draw(blue_sprite);
        window.draw(green_sprite);
        window.draw(red_sprite);
        window.draw(pink_sprite);
        window.draw(purple_sprite);
        window.draw(yellow_sprite);
        window.draw(dark_sprite);
        window.draw(light_sprite);
        if (clicked)

            window.draw(meaning_text);

        window.display();
    }
    write_file(arr);
}
