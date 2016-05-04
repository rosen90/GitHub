//1. Write a program that reads a string, reverses it and
//prints it on the console. Example: "sample" 
//"elpmas".

#include <iostream>
#include <string>
using namespace std;

int main()
{


	string name = "Rosen";

	string reverseName = "";

	for(int i = name.length() - 1; i >= 0 ; i--)
	{
//		cout << name.at(i);

		char ch = name.at(i);

		string s(1, ch);  // convert char to string.

		reverseName = reverseName.append(s);

	}

	cout << reverseName << endl;



	int len = reverseName.length();

	cout << "Lenght: " << len;

	return 0;
}
