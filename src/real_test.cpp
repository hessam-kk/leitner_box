#include "real_test.hpp"
#include "word.hpp"
#include "word_in_test.hpp"
#include "file.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <deque>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using std::array;
using std::cout;
using std::deque;
using std::endl;
using std::string;

void real_test(User &Primary)
{
    sf::RenderWindow window(sf::VideoMode(1600, 960), "Do The Test", sf::Style::Close);
    // Add a Background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("../assets/images/NewRed/Exam.png"))
        cout << "Error On Loading BackGround Image" << endl;
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    // End Of Adding Background
    // word Box top
    sf::Texture wordbox_top_texture;
    if (!wordbox_top_texture.loadFromFile("../assets/images/NewRed/wordbox_top.png"))
        cout << "Error On Loading wordbox top Image" << endl;
    sf::Sprite wordbox_top_sprite;
    wordbox_top_sprite.setTexture(wordbox_top_texture);
    wordbox_top_sprite.setPosition(758, 315);
    // word Box button
    sf::Texture wordbox_but_texture;
    if (!wordbox_but_texture.loadFromFile("../assets/images/NewRed/wordbox_but.png"))
        cout << "Error On Loading wordbox butt Image" << endl;
    sf::Sprite wordbox_but_sprite;
    wordbox_but_sprite.setTexture(wordbox_but_texture);
    wordbox_but_sprite.setPosition(758, 542);

    int cur_list;
    sf::Text cur_word, correct_mean, wrong_mean;
    array<deque<Word>, 7> arr;
    read_file(arr, Primary.get_username());
    deque<Word> total_words;
    // Store all words in a single list to aplly random
    for (size_t i = 0; i < 7; i++)
    {
        for (auto const &it : arr[i])
        {
            total_words.push_back(it);
        }
    }
    // Initializing the Test_word_list for test
    deque<Word_in_test> test_word_list;
    if (total_words.size() > 10)
    {
        while (test_word_list.size() < 10)
        {
            srand(time(NULL));
            Word_in_test tmp;
            // Setting Word
            int place = rand() % (total_words.size() - 1);
            std::string word = total_words.at(place).get_word();
            tmp.set_word(word);
            // Setting meaning
            std::string mean = total_words.at(place).get_meaning();
            tmp.set_meaning(mean);
            // Removing word to avoid duplication
            total_words.erase(total_words.begin() + place);
            // setting a random word for another opton(wrong meaning)
            srand(time(NULL));
            place = rand() % (total_words.size() - 1);
            tmp.set_wrong_meaning(total_words[place].get_word());
            // Adding it to list
            test_word_list.push_back(tmp);
        }
    }
    else
    {
        for (size_t i = 0; i < total_words.size() / 2; i++)
        {
            srand(time(NULL));
            Word_in_test tmp;
            // Setting Word
            int place = rand() % (total_words.size() - 1);
            std::string word = total_words.at(place).get_word();
            tmp.set_word(word);
            // Setting meaning
            std::string mean = total_words.at(place).get_meaning();
            tmp.set_meaning(mean);
            // Removing word to avoid duplication
            total_words.erase(total_words.begin() + place);
            // setting a random word for another opton(wrong meaning)
            srand(time(NULL));
            place = rand() % (total_words.size() - 1);
            tmp.set_wrong_meaning(total_words[place].get_word());
            // Adding it to list
            test_word_list.push_back(tmp);
        }
    }
    cout << test_word_list[0].get_word() << endl;
    cout << test_word_list[0].get_meaning() << endl;
    cout << test_word_list[0].get_wrong_meaning() << endl;
    cout << "----------" << endl;
    cout << test_word_list[1].get_word() << endl;
    cout << test_word_list[1].get_meaning() << endl;
    cout << test_word_list[1].get_wrong_meaning() << endl;
    int word_number = 0;

    while (window.isOpen())
    {
        window.draw(background_sprite);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close Window
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
            // Initialzing SFML type to show them
            cur_word.setString(test_word_list[word_number].get_word());
            correct_mean.setString(test_word_list[word_number].get_meaning());
            wrong_mean.setString(test_word_list[word_number].get_wrong_meaning());

            //  Mouse Moved
            if (event.type == sf::Event::MouseMoved)
            {
                // ADD Icon
                if (wordbox_top_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    window.draw(wordbox_top_sprite);
                }
                if (wordbox_but_sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                {
                    window.draw(wordbox_but_sprite);
                }
                
            }

            // Mouse Click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                cout << "Mouse: " << endl;
                // Choose corect Word
                if (correct_mean.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "correct mean pressed!" << endl;
                    word_number++;
                    cout << word_number << endl;
                }
                // Choose wrong Word
                if (wrong_mean.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cout << "wrong mean pressed!" << endl;
                    word_number++;
                    cout << word_number << endl;
                }
            }
        }
        // Prepairing Text
        sf::Font font;
        sf::Color color;
        font.loadFromFile("../assets/fonts/PlayfairDisplay-BoldItalic.ttf");
        cur_word.setFont(font);
        cur_word.setFillColor(sf::Color::Black);
        cur_word.setCharacterSize(50);
        cur_word.setPosition(250, 500);
        correct_mean.setFont(font);
        correct_mean.setFillColor(sf::Color::Black);
        correct_mean.setCharacterSize(50);
        correct_mean.setPosition(850, 400);
        wrong_mean.setFont(font);
        wrong_mean.setFillColor(sf::Color::Black);
        wrong_mean.setCharacterSize(50);
        wrong_mean.setPosition(850, 600);

        window.draw(cur_word);
        window.draw(correct_mean);
        window.draw(wrong_mean);
        window.display();
    }
}