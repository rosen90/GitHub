//12. Write a program that extracts from a given text all the
//sentences that contain given word. Example: The
//word is "in".

#include <iostream>
using namespace std;

int main()
{
	string text = "We are living in a yellow submarine. "
			"We don't have anything else. Inside the "
			"submarine is very tight. So we are drinking "
			"all the day. We will move out of it in 5 days.";

	int endSentance = text.find_first_of(".!?");
	int counter = 0;


	while (endSentance != string::npos)
	{
	   endSentance = text.find_first_of(".!?", endSentance+1);
	   counter++;
	}

	string santences[counter];

	int positionStart = 0;
	int positionEnd = text.find_first_of(".!?");

	for(int i = 0; i < counter; i++)
	{
		santences[i] = text.substr(positionStart, positionEnd +1 - positionStart);
		positionStart = positionEnd + 2;
		positionEnd = text.find_first_of(".!?", positionEnd+1);

	}

	string test = "in";
	bool check = 0;

	positionStart = 0;
	positionEnd = santences[0].find_first_of(" .,!?");

	for (int i = 0; i < counter; i++)
        {
            while (positionEnd != string::npos)
            {
                string word = santences[i].substr(positionStart, positionEnd - positionStart);

                if (test.compare(word) == 0)
                {
                    check = 1;
                }

                positionStart = positionEnd +1;
                positionEnd = santences[i].find_first_of(" .,!?", positionEnd + 1);
		}


		if (check == 1)
            {
                cout << santences[i] << endl;
            }

		positionStart = 0;
        positionEnd = santences[0].find_first_of(" .,!?");

		check = 0;
	}

	return 0;
}
