#include <iostream>
using namespace std;

//void printLine(int start, int end)
//{
//	for (int i = start; i <= end; i++)
//	{
//		cout << " " << i;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	cout << "n = ";
//
//	int n = 0;
//
//	cin >> n;
//	cout << endl;
//
//	for (int line = 1; line <= n; line++)
//	{
//		printLine(1, line);
//	}
//
//	for (int line = n - 1; line >= 1; line--)
//	{
//		printLine(1, line);
//	}
//
//	return 0;
//}

double fahrenheitToCelsius(double degrees)
{
	double celsius = (degrees - 32) * 5 / 9;
	return celsius;
}
int main()
{
	int temperature;

	cout << "Enter your body temperature in Fahrenheit degrees: ";
	cin >> temperature;
	temperature = fahrenheitToCelsius(temperature);
	cout << "Your body temperature in Celsius degrees is " << temperature
			<< ".";
	if (temperature >= 37)
		cout << "You are ill!" << endl;
return 0;
}
