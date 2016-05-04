#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

static int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int day, month, year;
short day_counter;

int isLeap(int y)
{
	return ((y % 4 == 0 && y % 100 !=0) || y % 400 == 0);
}

void nextDay()
{
	day += 1;
	day_counter++;

	if (day > days_in_month[month])
	{
		day = 1;
		month +=1;

		if (month > 12)
		{
			month = 1;
			year += 1;

			if(isLeap(year))
			{
				days_in_month[2] = 29;
			}
			else
			{
				 days_in_month[2] = 28;
			}
		}
	}
}

void setDate(int d, int m, int y)
{
	m < 1 ? m = 1 : 0;
	m > 12 ? m = 12 : 0;
	d < 1 ? d = 1 : 0;
	d > days_in_month[m] ? d = days_in_month[m] : 0;

	if (isLeap(y))
	{
		days_in_month[2] = 29;
	}
	else
	{
		days_in_month[2] = 28;
	}

	day = d;
	month = m;
	year = y;
}

void periodOfDays(int x)
{
    int i;
    for (i=0; i < x; i++)
    {
    	nextDay();
    }
}

void printDate()
{
    cout << "Future date is: " << day << "." << month << "." << year;
}

int main()
{

	int day, month, year;
	int period;

	cout << "Enter day: (0-31): ";
	cin >> day;
	cout << "Enter Month (0-12):";
	cin >> month;
	cout << "Enter a year (XXXX): ";
	cin >> year;



	cout << "Enter the period in days: ";
	cin >> period;

	setDate(day, month, year);
	periodOfDays(period);
	day_counter = 0;

	printDate();

	return 0;
}
