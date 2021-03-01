#include "../include/user.hpp"
#include <iostream>
#include <string>

void User::set_password(std::string const & x)
{
    this->password = x;
}
void User::set_username(std::string const & x)
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
