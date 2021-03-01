#pragma once
#include <iostream>
#include <string>

class User
{
public:
    void set_password(std::string const &);
    void set_username(std::string const &);
    std::string get_password() const;
    std::string get_username() const;

private:
    std::string username;
    std::string password;
};