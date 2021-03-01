#include "../include/file.hpp"
#include "../include/word.hpp"
#include "../include/user.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
void read_file(std::array<std::deque<Word>, 7> &arr)
{
    Word inword;
    std::string word;
    std::string meaning;
    unsigned short int day;

    std::ifstream in("../db.dat", std::ios::in);
    while (!in.eof())
    {
        getline(in, word, ':');
        if (word == "")
        {
            continue;
        }
        // in.ignore(); // ignore :
        getline(in, meaning, ';');
        in >> day;
        inword.set_word(word);
        inword.set_meaning(meaning);
        arr[day].push_back(inword);
        in.ignore(); // ignore \n
    }
    in.clear();
    in.close();
}

// word : meaning ;2
void write_file(std::array<std::deque<Word>, 7> &arr)
{
    std::ofstream out("../db.dat", std::ios::out);
    int i = 0;
    while (i < 7)
    {
        if (!arr[i].empty())
        {
            out << arr[i].front().get_word() << ':'    // write word
                << arr[i].front().get_meaning() << ';' // write meaning
                << i << std::endl;                     // write day
            arr[i].pop_front();                        // delete element
        }
        else
        {
            i++;
        }
    }
    out.clear();
    out.close();
}

User read_user()
{
    User userT;
    std::ifstream in("../userslist.txt", std::ios::in);
    if (!in)
    {
        std::cout << "error on file!" << std::endl;
    }
    string name, pass;
    while (!in.eof())
    {
        getline(in, name, ':'); // Reads User
        if (name == "")
        {
            continue;
        }
        in >> pass;
        userT.set_username(name);
        userT.set_password(pass);
        in.ignore(); // ignore \n
    }
    in.clear();
    in.close();
    return userT;
}
