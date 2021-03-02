#pragma once
#include "word.hpp"
#include "user.hpp"
#include <deque>
#include <array>

void read_file(std::array<std::deque<Word>, 7> &, std::string const &);
void write_file(std::array<std::deque<Word>, 7> &, std::string const &);
void write_user(User const &);
User read_user(std::string);