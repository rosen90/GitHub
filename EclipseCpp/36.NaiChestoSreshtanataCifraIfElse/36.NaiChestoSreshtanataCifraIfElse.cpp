
#include <iostream>
using namespace std;

int main()
{
	int num, maxElement, temp;
	int count0=0, count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;

	cout << "Enter a digit: ";
	cin >> num;


	while(num != 0)
	{
		temp = num % 10;
		num = num/10;

		switch(temp)
		{
			case 0: count0++; break;
			case 1: count1++; break;
			case 2: count2++; break;
			case 3: count3++; break;
			case 4: count4++; break;
			case 5: count5++; break;
			case 6: count6++; break;
			case 7: count7++; break;
			case 8: count8++; break;
			case 9: count9++; break;
		}
	}

	int maxCount = count0;
	maxElement = 0;

	if(count1 > maxCount)
		{
		maxCount = count1;
		maxElement = 1;
		}
	if(count2 > maxCount)
		{
			maxCount = count2;
			maxElement = 2;
		}
	if(count3 > maxCount)
		{
			maxCount = count3;
			maxElement = 3;
		}
	if(count4 > maxCount)
		{
			maxCount = count4;
			maxElement = 4;
		}
	if(count5 > maxCount)
		{
			maxCount = count5;
			maxElement = 5;
		}
	if(count6 > maxCount)
		{
			maxCount = count6;
			maxElement = 6;
		}
	if(count7 > maxCount)
		{
			maxCount = count7;
			maxElement = 7;
		}
	if(count8 > maxCount)
		{
			maxCount = count8;
			maxElement = 8;
		}
	if(count9 > maxCount)
		{
			maxCount = count9;
			maxElement = 9;
		}

	cout << "The most frequant digit is " << maxElement;

	return 0;
}
