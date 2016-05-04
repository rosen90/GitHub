//5. Write a program that extracts from a given file input.txt all words that are
//palindromes, e.g. "ABBA", "lamal", "exe" and stores these words in alphabetical
//order on separate lines in another file – palindromes.txt.
//Sample input file input.txt:

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

	ifstream readText("text.txt", ios::in);
	ofstream writeText("output.txt", ios::out);

	if (!readText)
	{
		cerr << "The file could not be open!";
		exit(1);
	}

	string word;

	unsigned int counter = 0;

	while (readText >> word)
	{

		for (unsigned i = 0; i < word.size(); i++)
		{
			char ch = word.at(i);
			ch = tolower(ch);
			word.at(i) = ch;
		}

		for (unsigned int j = 0, k = word.length() - 1; j < word.length() / 2;
				j++, k--) {

			if (word[j] == word[k])
			{
				counter++;
			}
		}

		if (counter == word.length() / 2)
		{
			cout << word << " ";
			writeText << word << " ";

		}

		counter = 0;
	}

	return 0;
}
