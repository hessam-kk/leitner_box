#include <iostream>
#include "../include/app.hpp"
#include "../include/login.hpp"
#include "../include/choose.hpp"
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
    else
    {
        // exam();
    }
    // app();
    return 0;
}