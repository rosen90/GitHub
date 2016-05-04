#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter value for a: ";
    cin >> a;

    cout << "Enter value for b: ";
    cin >> b;

    cout << "Enter value for c: ";
    cin >> c;

    if(a>b)
        {
            if(a>c)
                {
                    cout << "The bigger number is " << a;
                }
            else
                {
                    cout << "The bigger number is " << c;
                }
        }
        else
            {
                if(b>c)
                    {
                        cout << "The bigger number is " << b;
                    }
                else
                    {
                        cout << "The bigger number is " << c;
                    }
            }

    return 0;
}
