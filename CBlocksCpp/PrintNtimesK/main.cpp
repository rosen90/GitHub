//1. ������ �� ���� ����� K � N (N > 0). �������� N ���� ������� �.

#include <iostream>

using namespace std;

int main()
{
    int n,k;

    cout << "Enter value for N (N>0): ";
    cin >> n;

    cout << "Enter value for K: ";
    cin >> k;

    for (int i = 1; i <= n; i++)
        {
            if( i == n)
                {
                    cout << k;
                }
            else
                {
                    cout << k << ", ";
                }

        }

    return 0;
}
