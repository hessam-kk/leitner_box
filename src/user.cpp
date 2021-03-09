#include "user.hpp"
#include <iostream>
#include <string>

User::User() {}

User::User(std::string x)
{
    this->username = x;
}

User::User(std::string username, std::string password) : User(username)
{
    this->password = password;
}

void User::set_password(std::string const &x)
{
    this->password = x;
}
void User::set_username(std::string const &x)
{
    this->username = x;
}
std::string User::get_password() const
{
    return this->password;
}
std::string User::get_username() const
{
    return this->username;
}

User User::operator++(int)
{
    // Calcualte Last Test statistics
    // last_one.avg_score = last_one.corrects - (1 / 3 * last_one.wrongs) / last_one.total_questions+1;
    // Calculate the new avg score and increase total tests count
    // avg_scores = ((total_tests+1) * avg_scores + last_one.avg_score) / ++total_tests;
    this->total_tests++;
    this->total_scores += last_one.avg_score;
}

unsigned int User::get_total_test() const
{
    return this->total_tests;
}

int User::get_total_score() const
{
    return this->total_scores;
}
last_test User::get_last_test() const
{
    return this->last_one;
}
