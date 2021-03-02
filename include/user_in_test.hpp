#pragma once

#include "user.hpp"
#include "word.hpp"
#include <array>
#include <deque>

class User_in_test : User
{
public:
    Word get_word();
    std::string get_random_meaning();

private:
    std::array<std::deque<Word>, 7> arr;
};