// Даден е текстов файл съдържащ текст на няколко реда....
//Rosen Karadinev


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {

	map<string, int> countWords;
	vector<string> wordsKP;
	set<string, greater<string> > sortedWords;

	int K, P;
	cout << "Enter K: ";
	cin >> K;
	cout << "Enter P: ";
	cin >> P;

	ifstream readText("text.txt", ios::in);

	if (!readText) {
		cerr << "The file coud not be opened !!!";
		exit(1);
	}

//clear text
	string text;
	string word;
	while (readText >> word) {
		text.append(word + " ");
	}

	int position = text.find_first_of(".,?!-:();\"", 0);
	while (position != string::npos) {
		text.replace(position, 1, "");
		position = text.find_first_of(".,?!-:();\"", position);
	}

	for (unsigned i = 0; i < text.size(); i++) {
		char ch = text.at(i);
		ch = tolower(ch);
		text.at(i) = ch;
	}

	stringstream ss;
	ss.str(text);

	string wordFromFile;

// Enter words in map
	while (ss >> wordFromFile) {
		countWords[wordFromFile]++;
		wordsKP.push_back(wordFromFile);

	}
	readText.clear();
	readText.seekg(0);

	map<string, int>::iterator it;

	cout << "Words Counter: \n\n";
	for (it = countWords.begin(); it != countWords.end(); it++) {

		stringstream aa;
		stringstream bb;
		string result;
		aa << it->first;
		bb << it->second;

		result.append(bb.str() + "->" + aa.str());
		sortedWords.insert(result);

		aa << "";
		bb << "";
		result = "";

		cout << it->first << " -> " << it->second << endl;
	}

	multimap<int, string > onlyKP;

	for(unsigned int i = 0; i < wordsKP.size(); i++)
	{
		int size = wordsKP[i].size();
		if(size > K && size < P)
		{
			onlyKP.insert(pair<int,string>(size , wordsKP[i]));
		}
	}

	cout << "\nWords with size  >K and <P " << endl;

	for (multimap<int,string>::iterator it = onlyKP.begin(); it != onlyKP.end(); it++)
	{
		cout << it->second << endl;
	}

	return 0;
}
