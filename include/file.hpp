#pragma once
#include "word.hpp"
#include <deque>
#include <array>

void read_file(std::array<std::deque<Word>, 7> &);
void write_file(const std::array<std::deque<Word>, 7> &);