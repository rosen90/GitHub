#include <iostream>

using namespace std;

int main ()
{
    int num, CopyOfNum, maxIndex, temp;
    int digitCount[10] = {0};

    cout << "Enter a number: ";
    cin >> num;

    CopyOfNum = num;


    while(CopyOfNum != 0)
    {
    	temp = CopyOfNum % 10;
    	CopyOfNum = CopyOfNum / 10;

    	digitCount[temp]++;
    }

    int maxElement = digitCount[0];

    for(int i = 0; i < sizeof(digitCount); i++)
    {
    	if(digitCount[i] > maxElement)
    	{
    		maxElement = digitCount[i];
    		maxIndex = i;
    	}
    }


    cout << "Nai-chesto sreshtanata cifra e: " << maxIndex;

    return 0;

}
