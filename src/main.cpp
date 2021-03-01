#include "../include/login.hpp"
#include "../include/choose.hpp"
#include "../include/app.hpp"
#include "../include/test_summery.hpp"

#include <iostream>
using namespace std;

struct last_test
{
    unsigned short int total_questions = 0;
    double avg_score = 0;
    unsigned int corrects = 0;
    unsigned int wrongs = 0;
};

int main()
{
    // login();
    if (choose() == 0) // learn
    {
        app();
    }
    else // Exam 
    {
        test_summery();
    }
    // app();
    return 0;
}