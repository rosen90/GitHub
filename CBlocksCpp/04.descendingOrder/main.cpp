//4. Write a program that sorts 3 real values in descending
//order using nested if statements.

#include <iostream>

using namespace std;

int main()
{
    int a, b ,c;

    cout << "a= ";
    cin >> a;

    cout << "b= ";
    cin >> b;

    cout << "c= ";
    cin >> c;

    if (a > b)
        {
            if (b > c)
                {
                    cout << a << ", " << b << ", " << c;
                }
        }
    if (a > c)
        {
            if (c > b)
                {
                  cout << a << ", " << c << ", " << b;
                }
        }
    if (b > a)
        {
            if (a > c)
                {
                    cout << b << ", " << a << ", " << c;
                }
        }
    if (b > c)
        {
            if(c > a)
                {
                    cout << b << ", " << c << ", " << a;
                }
        }
    if(c > a)
        {
            if(a > b)
                {
                    cout << c << ", " << a << ", " << b;
                }
        }
    if(c > b)
        {
            if(b > a)
                {
                    cout << c << ", " << b << ", " << a;
                }
        }

    return 0;
}
