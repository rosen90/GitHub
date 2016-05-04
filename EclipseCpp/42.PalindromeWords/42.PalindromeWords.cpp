//9. Write a program that extracts from a given text all the
//words that are palindromes, e.g. "ABBA", "lamal", "exe“.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    string text;
    cout << "Enter text: ";

    getline(cin, text);

	int wordCount=0;
	int oldSpace = 0;
	int space = text.find(" ");


	 stringstream ss (text);
	 string word;

	 while ( ss >> word )
	 {
		 wordCount++;
	 }

     cout << "The palindrome words : ";

	 for (int i = 0; i < wordCount; i++)
        {
            word = text.substr(oldSpace, space - oldSpace);
            oldSpace = space + 1;
            space = text.find_first_of(" ", space + 1);

             int counter = 0;

            for ( int j =0, k = word.length() - 1; j < word.length()/2; j++, k--)
                {

                    if(word[j] == word[k])
                        {
                            counter++;
                        }
                }

                if(counter == word.length()/2)
                    {
                        cout << word << " ";
                    }
        }

    return 0;
}
