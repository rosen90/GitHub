#include <iostream>
using namespace std;

int main()
{

	int day, mounth, year;
	int period;

	cout << "Enter a year (XXXX): ";
	cin >> year;
	cout << "Enter Month (0-12):";
	cin >> mounth;
	cout << "Enter day: (0-30): ";
	cin >> day;

	cout << "Enter the period in days: ";
	cin >> period;

	int temp;
	int temp2 = period;



	temp = ((period % 365) % 30);
	day += temp;

	if(day > 30)
	{
		mounth++;
		day %= 30;
	}

	temp = period % 365;
	period = temp;
	temp = period / 30;
	mounth += temp;

	if(mounth > 12)
	{
		year++;
		mounth %= 12;
	}

	period = temp2;
	temp = period / 365;
	year += temp;

	if(year % 4 == 0)
	{
		day +=1;
	}

	cout << "Future date: " <<  year <<", " << mounth << ", " << day;







	return 0;
}
