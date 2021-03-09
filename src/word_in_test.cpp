#include "word_in_test.hpp"

void Word_in_test::set_wrong_meaning(std::string x )
{
    this->wrong_meaning = x;
}
std::string Word_in_test::get_wrong_meaning()
{
    return this->wrong_meaning;
}