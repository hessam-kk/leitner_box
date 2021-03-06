#pragma once
#include "word.hpp"

class Word_in_test : Word
{
public:
    void set_wrong_meaning(std::string);
    std::string get_wrong_meaning();
private:
    std::string wrong_meaning;
};