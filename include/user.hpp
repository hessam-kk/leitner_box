#pragma once
#include <iostream>
#include <string>
struct last_test
{
    unsigned short int total_questions = 0;
    int score = 0;
    unsigned int corrects = 0;
    unsigned int wrongs = 0;
};
class User
{
    friend void write_user(User const &);
    friend User read_user(std::string);

public:
    User();
    User(std::string);
    User(std::string, std::string);
    virtual void set_password(std::string const &) final;
    virtual void set_username(std::string const &) final;
    std::string get_password() const;
    std::string get_username() const;
    User operator++(int);
    unsigned int get_total_test() const;
    int get_total_score() const;
    last_test get_last_test() const;
    last_test last_one;
    void add_total_score(int);
    void add_total_test();
private:
    std::string username;
    std::string password;
    unsigned int total_tests = 0;
    int total_scores = 0;
};