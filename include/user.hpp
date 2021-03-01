#pragma once
#include <iostream>
#include <string>
struct last_test
{
    unsigned short int total_questions = 0;
    double avg_score = 0;
    unsigned int corrects = 0;
    unsigned int wrongs = 0;
};
class User
{
    friend User read_user(std::string);

public:
    User();
    User(std::string);
    User(std::string, std::string);
    void set_password(std::string const &);
    void set_username(std::string const &);
    std::string get_password() const;
    std::string get_username() const;
    User operator++();
    unsigned int get_total_test() const;
    double get_avg_score() const;
    last_test get_last_test() const;
private:
    std::string username;
    std::string password;
    unsigned int total_tests = 0;
    double avg_scores = 0;
    last_test last_one;
};