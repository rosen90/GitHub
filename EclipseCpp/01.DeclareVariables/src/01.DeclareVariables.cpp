#include<iostream>
#include<conio.h>

using namespace std;

int main() {

	int number, count = 0;
	cout << "Enter a number: ";
	cin >> number;

	for (int a = 2; a < number; a++) {
		if (number % a == 0) {
			count++;
		}
	}

	if (count == 0) {
		cout << "Prime number \n";
	} else {
		cout << "Not a prime number \n";
	}
}
