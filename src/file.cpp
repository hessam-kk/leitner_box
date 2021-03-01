#include "../include/file.hpp"
#include "../include/word.hpp"
#include "../include/user.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;

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

void write_user(User &my_user)
{
    User tmp;
    system("pwd");
    std::ofstream out("../userslist.dat", std::ios::app | std::ios::binary);
    std::ifstream in("../userslist.dat", std::ios::ate | std::ios::in | std::ios::binary);
    if (!in.is_open())
    {
        std::cerr << "Error on file opening" << std::endl;
        return;
    }

    in.seekg(std::ios::beg);
    // Search For duplicate
    while (!in.eof())
    {
        in.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
        if (tmp.get_username() == my_user.get_username())
        {
            in.close();
            return;
        }
    }
    out.seekp(std::ios::end);
    out.write(reinterpret_cast<const char *>(&my_user), sizeof(my_user));
    cout << "Saved!" << endl;
    out.flush();
    out.clear();
    out.close();
}

User read_user(std::string const &main_username)
{
    User tmp;
    std::ifstream in("../userslist.dat", std::ios::in | std::ios::binary);
    in.seekg(0, std::ios::beg);
    if (!in)
    {
        std::cout << "error on file!" << std::endl;
    }
    while (!in.eof())
    {
        in.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
        if (tmp.get_username() == main_username)
        {
            cout << "Read User:" << tmp.get_username() << ' ' << tmp.get_password() << endl;
            in.clear();
            in.close();
            return tmp;
        }
    }
    in.clear();
    in.close();
    return User("404");
}
