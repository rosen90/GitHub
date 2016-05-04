// 1. Write an if statement that examines two integer
// variables and exchanges their values if the first one is
// greater than the second one.

#include <iostream>

using namespace std;

int main()
{
    int a = 12;
    int b = 9;

    int temp;

    if(a > b)
        {
            temp = a;
            a = b;
            b = temp;

            cout << " a = " << a << ", b = " << b;
        }
    else
        {
            cout << "No exchange needed!";
        }


    return 0;
}
