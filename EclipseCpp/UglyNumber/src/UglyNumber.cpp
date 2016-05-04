#include <iostream>
using namespace std;


//Write a program to check whether a given number is an ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//Note that 1 is typically treated as an ugly number.


int maxDivide(int, int);
bool isUgly(int);

int main()
{
	int number;

	cout << "Enter a number: ";
	cin >> number;

	if(isUgly(number))
	{
		cout << number << " is a Ugly number!";
	}
	else
	{
		cout << number << " is not a Ugly number!";
	}

	return 0;
}


int maxDivide(int a, int b)
{
  while (a % b == 0)
  {
	  a = a / b;
  }

  return a;
}

bool isUgly(int num)
{
  if(num != 0)
  {
	  num = maxDivide(num, 2);
	  num = maxDivide(num, 3);
	  num = maxDivide(num, 5);

	  return (num == 1)? 1 : 0;
  }

  return false;
}
