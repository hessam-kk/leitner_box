#include "../include/user.hpp"
#include <iostream>
#include <string>

void User::set_password(std::string x)
{
    this->password = x;
}
void User::set_username(std::string x)
{
    this->username = x;
}
std::string User::get_password() const
{
    std::cout << this->password << std::endl;
    return this->password;
}
std::string User::get_username() const
{
    return this->username;
}
