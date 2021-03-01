#pragma once
#include <iostream>
#include <string>
struct last_test
{
    unsigned short int total_questions;
    double avg_score;
    unsigned int corrects;
    unsigned int wrongs;
};
class User
{
public:
    User();
    User(std::string);
    void set_password(std::string const &);
    void set_username(std::string const &);
    std::string get_password() const;
    std::string get_username() const;
    User operator++();
private:
    std::string username = "";
    std::string password = "";
    unsigned int total_tests = 0;
    double avg_scores = 0;
    last_test last_one;
};