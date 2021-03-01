#include <iostream>
#include "../include/app.hpp"
#include "../include/login.hpp"
using namespace std;

int main()
{
    if (login())
    {
        app();
    }
    return 0;
}