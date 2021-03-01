#include "file.hpp"
#include "word.hpp"
#include "user.hpp"
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

void write_user(User const & u)
{
    std::ofstream out("../userslist.dat", std::ios::app);
    if (!out)
    {
        cout << "error open out file" << endl;
    }
    out << '[' + u.get_username() + ':' + u.get_password() + ',';
    out << u.get_total_test() + ',' + u.get_avg_score() + ',' ;
    out << u.get_last_test().total_questions + ',' +  u.get_last_test().avg_score + ',';
    out <<  u.get_last_test().corrects + ',' +  u.get_last_test().wrongs + ']';
    out.flush();
    out.clear();
    out.close();
    cout << "End write user ";
}

User read_user(std::string main_username)
{
    std::ifstream in("../userslist.dat", std::ios::binary);
    if (!in)
    {
        cout << "error open in file" << endl;
    }
    in.seekg(0, std::ios::beg);
    while (!in.eof())
    {
        cout << "while" << endl;
        User tmp_user;
        in.read(reinterpret_cast<char *>(&tmp_user), sizeof(User));

        cout << "while2" << endl;
        if (tmp_user.get_password() == main_username)
        {
            cout << "found" << endl;
            return tmp_user;
        }
    }
    cout << "not found " << endl;
    return User("404");
}