#pragma once
#include <string>
using std::string;

class Word
{
public:
    void set_word(string);
    string get_word() const;
    void set_meaning(string);
    string get_meaning() const;
    void set_day(unsigned short int);
    unsigned short int get_day() const;
private:
    string word;
    string meaning;    
    unsigned short int current_day = 0;
};