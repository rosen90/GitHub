//7. Write a program that reads a string from the console
//and lists all the different letters in the string along with
//information how many times each letter is found.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	cout << "Write a string: ";
	getline(cin, str1);
	string str2 = "";

	int alphabet[26] = {0};
	char a = 'a';


	for(unsigned i = 0; i < str1.length(); i++)
		{

			char ch = str1.at(i);

			if (isupper(ch))
			{
				ch = tolower(ch);
			}


			string s(1, ch);  // convert char to string.
			str2 = str2.append(s);
		}

		for (unsigned i = 0; i < str1.length(); i++)
            {
                char ch = str1.at(i);
                alphabet[(int)ch - (int)a]++;
            }

    for (int i = 0; i < 26; i++)
        {
            if(alphabet[i] != 0)
                {
                    cout <<  char(i + 97) << " - " << alphabet[i] << endl;
                }
        }

	return 0;
}
