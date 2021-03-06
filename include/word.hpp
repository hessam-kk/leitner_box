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

private:
    string word;
    string meaning;    
};