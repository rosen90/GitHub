//3. Write a program that inputs a string and prints the
//string backward. Convert all uppercase characters to
//lowercase and all lowercase characters to uppercase.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word = "";
	cout << "Enter a string: ";
	getline(cin, word);

	string reverseString = "";


	for(int i = word.length() - 1; i >= 0 ; i--)
		{

			char ch = word.at(i);

			if (isupper(ch))
			{
				ch = tolower(ch);
			}
			else
			{
				ch = toupper(ch);
			}

			string s(1, ch);  // convert char to string.

			reverseString = reverseString.append(s);

		}

	cout << reverseString;

	return 0;
}
