// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>

#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {

char number1[10];
char number2[10];
char number3[10];
char number4[10];

cout << "number1? ";
cin >> number1;
cout << "number2? ";
cin >> number2;
cout << "number3? ";
cin >> number3;
cout << "number4? ";
cin >> number4;

cout << "The sum is: " << strtod(number1, NULL) + strtod(number2, NULL)
+ strtod(number3, NULL) + strtod(number4, NULL);


	return 0;
} // end main
