#include <iostream>
#include <vector>
using namespace std;

//Write a program to find the n-th ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//Note that 1 is typically treated as an ugly number.

int nthUglyNumber(int );
vector<int> numbers;

int main()
{
	cout << nthUglyNumber(10);

	return 0;
}


int nthUglyNumber(int n)
{
	numbers.push_back(1);
	int start2 = 0;
	int start3 = 0;
	int start5 = 0;

	while((int)numbers.size() < n)
	{

		int result;
		if(numbers[start2] * 2 <= numbers[start3] * 3 && numbers[start2] * 2 <= numbers[start5] * 5) {
			result = numbers[start2] * 2;
			if(result != numbers[numbers.size() - 1]) {
				numbers.push_back(result);
			}
			start2++;
		} else if (numbers[start3] * 3 <= numbers[start2] * 2 && numbers[start3] * 3 <= numbers[start5] * 5) {
			int result = numbers[start3] * 3;
			if(result != numbers[numbers.size() - 1]) {
				numbers.push_back(result);
			}
			start3++;
		} else if (numbers[start5] * 5 <= numbers[start2] * 2 && numbers[start5] * 5 <= numbers[start3] * 3) {
			int result = numbers[start5] * 5;
			if(result != numbers[numbers.size() - 1]) {
				numbers.push_back(result);
			}
			start5++;
		}
	}

	return numbers[numbers.size() - 1];
}
