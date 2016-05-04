//Write a program that finds how many times a
//substring is contained in a given text (perform case
//insensitive search).

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    string text = "We are living in a yellow submarine. We don't have anything else. Inside the submarine is very tight. So we are drinking all the day. We will move out of it in 5 days.";
    string convertedToLower = "";

    int counter = 0;
    int position = text.find("in");

    	for(int i = 0; i < text.length() - 1 ; i++)
		{

			char ch = text.at(i);

			if (isupper(ch))
			{
				ch = tolower(ch);
			}

			string s(1, ch);  // convert char to string.

			convertedToLower = convertedToLower.append(s);
		}

    cout << text << endl << endl;

    text = convertedToLower;

    while (position != string::npos)
        {
            position = text.find("in", position + 1);
            counter++;
        }

    cout << "Result: " << counter;


    return 0;
}
