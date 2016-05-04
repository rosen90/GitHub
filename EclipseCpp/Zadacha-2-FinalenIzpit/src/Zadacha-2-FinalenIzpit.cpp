//Даден е текс, които се чете от конзолата.
//Да се намери и изведе думата, която се среща K пъти.
//Росен Карадинев

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "Enter your text here: ";
	getline(cin, text);

	int k;
	cout << "K= ";
	cin >> k;

	int endWord = text.find_first_of(" ,-:");
	int counter = 1;

	    while (endWord != string::npos)
	        {
	            endWord = text.find_first_of(" ,-:", endWord + 1);
	            counter++;
	        }


	    cout << endl;

	    string words[counter];

	    int startPosition = 0;
	    int endPosition = 0;

	    for (int i = 0; i < counter;i++)
	    {
	        endPosition = text.find(" ", endPosition + 1);

	        if (i==0)
	        {
	            words[i]=text.substr(startPosition,endPosition - startPosition);
	            startPosition = endPosition;
	        }
	        else
	        {
	            words[i]=text.substr(startPosition+1, endPosition - startPosition-1);
	            startPosition = endPosition;
	        }
	    }

	       string kRepeatedWord;

	       for (int i=0; i < counter;i++)
	       {
	           endWord = 0;
	           int wordCounter = 0;
	           int startPosition = endWord;

	           while (endWord != string::npos)
	           {
	        	   endWord = text.find(words[i], startPosition);
	               startPosition = endWord + 1;

	               if (endWord == string::npos)
	               {
	                   break;
	               }

	               wordCounter++;

	               if (wordCounter == k)
	               {
	            	   kRepeatedWord = words[i];
	                   break;
	               }
	           }
	       }

	       cout << "The word that is repeated " << k << " times is ";
	       cout << kRepeatedWord << endl;

	return 0;
}
