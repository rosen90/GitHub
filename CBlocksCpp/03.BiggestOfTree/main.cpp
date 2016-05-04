//3. Write a program that finds the biggest of three integers
//using nested if statements.

#include <iostream>

using namespace std;

int main()
{
    int a = 45;
    int b = 3;
    int c = 74;

    if(a > b)
        {
            if (a > c)
                {
                    cout << "The biggest is a ->> " << a;
                }
        }
        if(b > a)
        {
            if (b > c)
                {
                    cout << "The biggest is b ->> " << b;
                }
        }
        if(c > b)
        {
            if (c > a)
                {
                    cout << "The biggest is c ->> " << c;
                }
        }

    return 0;
}
