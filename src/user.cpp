#include "user.hpp"
#include <iostream>
#include <string>

User::User() {}

User::User(std::string x)
{
    this->username = x;
}

User::User(std::string username, std::string password): User(username)
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
    return password;
}
std::string User::get_username() const
{
    return username;
}

User User::operator++()
{
    // Calcualte Last Test statistics
    last_one.avg_score = last_one.corrects - (1 / 3 * last_one.wrongs) / last_one.total_questions;
    // Calculate the new avg score and increase total tests count
    avg_scores = (total_tests * avg_scores + last_one.avg_score) / ++total_tests;
}
