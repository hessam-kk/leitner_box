#pragma once
#include "word.hpp"
#include "user.hpp"
#include <deque>
#include <array>

void read_file(std::array<std::deque<Word>, 7> &);
void write_file(std::array<std::deque<Word>, 7> &);
void write_user(User );
User read_user(std::string );