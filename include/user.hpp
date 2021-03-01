#pragma once
#include <iostream>
#include <string>

class User
{
public:
    void set_password(std::string);
    void set_username(std::string);
    std::string get_password() const;
    std::string get_username() const;

private:
    std::string username;
    std::string password;
};