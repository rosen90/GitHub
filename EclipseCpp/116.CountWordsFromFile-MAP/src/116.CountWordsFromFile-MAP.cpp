#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int main()
{
	map<string, int> wordOccuriences;
	set<string, greater<string> > sortedWords;

	ifstream readText("text.txt", ios::in);
	ofstream writeText("resultText.txt", ios::out);

	if(!readText)
	{
		cerr << "The file could not be opened !!!";
		exit(1);
	}

	string tempText;
	string clearText;

	while(readText >> tempText)
	{
		clearText.append(tempText + " ");
	}

	int position = clearText.find_first_of(".,?!-:\'();\"", 0);

	while(position != string::npos)
	{
		clearText.replace(position, 1, "");
		position = clearText.find_first_of(".,?!-:\'();\"", position);
	}


	for(unsigned int i = 0; i < clearText.size(); i++)
	{
		char ch = clearText.at(i);
		ch = tolower(ch);
		clearText.at(i) = ch;
	}

	stringstream ss;
	ss.str(clearText);

	string wordFromFile;

	while(ss >> wordFromFile)
	{
		wordOccuriences[wordFromFile]++;
	}

	readText.clear();
	readText.seekg(0);



	map<string, int>::iterator it;

	cout << "Enter P: ";
	int minValue;
	cin >> minValue;

	for(it = wordOccuriences.begin(); it != wordOccuriences.end(); it++)
	{
		stringstream aa;
		stringstream bb;
		string result;

		aa << it->first;
		bb << it->second;

		result.append(bb.str() + " -> " + aa.str());
		sortedWords.insert(result);

		aa<<"";
		bb<<"";
		result="";

//		if(it->second < minValue)
//		{
//			minValue = it->second;
//		}

//		cout << it->first << " -> " << it->second << endl;  OPTIONAL!!!
	}

//Most Repeated Word in text!!!
	for(it = wordOccuriences.begin(); it != wordOccuriences.end(); it++)
	{
		if(it->second == minValue)
		{
			cout << it->first << "->" << it->second << endl;
		}

	}

// Sort Words by frequancy and print it
//	for(set<string>::iterator it = sortedWords.begin(); it != sortedWords.end(); it++)
//	{
//		cout << *it << endl;
//	}

	return 0;
}
