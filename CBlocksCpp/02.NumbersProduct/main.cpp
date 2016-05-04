//2. Write a program that shows the sign (+ or -) of the
//product of three real numbers without calculating it.
//Use sequence of if statements.

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, count = 0;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

    if (a == 0 || b == 0 || c == 0)
        {
            cout << "Zero";
        }
    else
        {
            if(a < 0)
                {
                    count++;
                }
            if(b < 0)
                {
                    count++;
                }
            if ( c < 0)
                {
                    count++;
                }

        if(count % 2 !=0)
            {
                cout << "Negative";
            }
        else
            {
                cout << "Positive";
            }
        }


    return 0;
}
