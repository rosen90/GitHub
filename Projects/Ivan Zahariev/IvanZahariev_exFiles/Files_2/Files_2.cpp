//============================================================================
// Name        : Files_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()

{
	int countRow = 0;
	string newRow;

	ifstream inFile("Text.txt", ios::in);
	ofstream outFile("newText.txt", ios::out);
	if (!inFile)
	{
		cerr<<"File (Text.txt) could not be opened!"<<endl;
		exit( 1 );
	}

		if (!outFile)
		{
			cerr<<"File (newText.txt) could not be opened!"<<endl;
			exit( 1 );
		}

		while(getline(inFile, newRow))
		{
			countRow++;
			outFile<< countRow << " " << newRow << endl;
//			cout<<newRow<<endl;
		}




	return 0;
}
