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
// void Word::set_day(unsigned short int x)
// {
//     this->current_day = x;
// }
// unsigned short int Word::get_day() const
// {
//     return this->current_day;
// }