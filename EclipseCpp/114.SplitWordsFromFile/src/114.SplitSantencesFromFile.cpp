//Split file text on words

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	ifstream readText("text.txt", ios::in); //seekg()
	ofstream writeText("result.txt", ios::out); //seekp()

	if(!readText)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string textFromFile;
	string strText;

	while(readText >> textFromFile )
	{
		strText.append(textFromFile + " ");
	}

	readText.clear();
	readText.seekg(0);


	vector<string> santences;
	string santence;

	int startPosition =  0;
	int endPosition = strText.find_first_of(".!?;", startPosition);

	while(endPosition != string::npos)
	{
		santences.push_back(strText.substr(startPosition, endPosition - startPosition + 1));
		startPosition = endPosition + 2;
		endPosition = strText.find_first_of(".!?;", startPosition  + 1);
	}

	for(unsigned int i = 0; i < santences.size(); i++)
	{
		cout << santences[i] << endl << endl;
		writeText << santences[i] << endl;
	}

	return 0;
}
