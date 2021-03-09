#include "../include/word.hpp"

void Word::set_word(string x)
{
    this->word = x;
}
string Word::get_word() const
{
    return this->word;
}
void Word::set_meaning(string x)
{
    this->meaning = x;
}
string Word::get_meaning() const
{
    return this->meaning;
}
