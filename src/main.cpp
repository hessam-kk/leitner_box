#include "login.hpp"
#include "choose.hpp"
#include "app.hpp"
#include "user.hpp"
#include "file.hpp"
#include "test_summery.hpp"

#include <iostream>
using namespace std;

int main()
{
    User Primary;
    // Primary = read_user("hes");?
    // cout << Primary.get_password() << endl;
    if (login(Primary))
    {
        cout << Primary.get_password() << endl;
        if (choose() == 0) // learn
        {
            app();
        }
        else // Exam
        {
            test_summery();
        }
        // app();
    }
    return 0;
}