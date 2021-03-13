#include "file.hpp"
#include "word.hpp"
#include "user.hpp"
#include "sha256.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>

using std::cerr;
using std::cout;
using std::endl;

void read_file(std::array<std::deque<Word>, 7> &arr, std::string const &Username)
{
    Word inword;
    std::string word;
    std::string meaning;
    unsigned short int day;

    std::ifstream in("../db_" + Username + ".dat", std::ios::in);
    if (!in)
    {
        cerr << "Error on opening the file db_" + Username + ".dat" << endl;
        string commnand = "cp ../db.dat ../db_" + Username + ".dat";
        system(commnand.c_str());
        sleep(1);
        std::fstream in("../db_" + Username + ".dat");
    }
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
void write_file(std::array<std::deque<Word>, 7> &arr, std::string const &Username)
{
    std::ofstream out("../db_" + Username + ".dat", std::ios::out);
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

void write_user(User const &u)
{
    std::ofstream out("../userslist.dat", std::ios::app);
    std::ifstream in("../userslist.dat", std::ios::in);
    if (!out)
    {
        cout << "error open out file" << endl;
    }

    while (!in.eof())
    {
        // in.ignore();
        string username = "";
        getline(in, username, ' ');
        if (username == u.get_username())
        {
            out << u.get_username() << ' ' << u.get_password() + ',';
            out << u.get_total_test() << ' ' << u.get_total_score() << ' ';
            out << u.get_last_test().total_questions << ' ' << u.get_last_test().score << ' ';
            out << u.get_last_test().corrects << ' ' << u.get_last_test().wrongs << '\n';
            out.flush();
            out.clear();
            out.close();
            cout << "End over write user ";
            return;
        }
    }
    out.seekp(std::ios::end);
    cout << "start write user " << endl;
    SHA256 sha256;
    out << u.get_username() << ' ' << sha256(u.get_password()) + ',';
    out << u.get_total_test() << ' ' << u.get_total_score() << ' ';
    out << u.get_last_test().total_questions << ' ' << u.get_last_test().score << ' ';
    out << u.get_last_test().corrects << ' ' << u.get_last_test().wrongs << '\n';

    out.flush();
    out.clear();
    out.close();
    cout << "End write user " << endl;
}

User read_user(std::string main_username)
{
    std::ifstream in("../userslist.dat");
    if (!in)
    {
        cout << "error open in file" << endl;
    }
    in.seekg(0, std::ios::beg);

    User tmp_user;
    bool done = false;
    while (!in.eof())
    {
        string username;
        in >> username;

        if (username == main_username)
        {
            cout << "found" << endl;
            tmp_user.username = username;
            in.ignore();
            getline(in, tmp_user.password, ',');
            in >> tmp_user.total_tests               //
                >> tmp_user.total_scores             //
                >> tmp_user.last_one.total_questions //
                >> tmp_user.last_one.score       //
                >> tmp_user.last_one.corrects        //
                >> tmp_user.last_one.wrongs;
            in.ignore(2); // ignore -
            done = true;
        }
    }
    if (done)
        return tmp_user;
    cout << "not found " << endl;
    return User("404");
}
