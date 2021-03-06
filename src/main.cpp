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
    // Primary = read_user("hes");
    // cout << Primary.get_password() << endl;
    if (login(Primary))
    {

        // int T = choose();
        // if (T == 0) // learn
        // {
        //     app(Primary);
        // }
        // else if (T == 1) // Exam
        // {
            test_summery(Primary);
        // }
    }
    return 0;
}