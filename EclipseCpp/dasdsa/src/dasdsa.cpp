#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

typedef multimap<string, int, less<int> > Mmid;

int main()
{

	string str =
			"This is the TEXT. Text, text, text THIS TEXT! Is this the text?";
	int position = str.find_first_of(".,!?:", 0);
	while (position != string::npos) {
		str.replace(position, 1, "");
		position = str.find_first_of(".,!?:", position + 1);
	}
	string newStr;
	for (unsigned i = 0; i < str.size(); i++) {
		char ch = str.at(i);
		if (isupper(ch)) {
			ch = tolower(ch);
			newStr += ch;
		} else {
			ch = tolower(ch);
			newStr += ch;
		}
		if (isspace(ch)) {
			newStr += ch;
		}
	}

	int wordCount = 0;


	stringstream ss(newStr);
	string word;

	while (ss >> word)
	{
		wordCount++;
	}

	istringstream iss(newStr);

	map<string, size_t> occurrences;

	while (iss >> word)
	{
		++occurrences[word];
	}

	for (map<string, size_t>::iterator it = occurrences.begin();
			it != occurrences.end(); ++it) {
		cout << it->first << "->" << it->second << endl;
	}


	return 0;
}
