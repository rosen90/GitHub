#include <iostream>

using namespace std;

int main()
{
    int number;

    cout << "Enter value for number: ";
    cin >> number;

    if(number % 2 == 0)
        {
            cout << "The number " << number << " is even.";
        }
    else
        {
            cout << "The number " << number << " is odd.";
        }

    return 0;
}
