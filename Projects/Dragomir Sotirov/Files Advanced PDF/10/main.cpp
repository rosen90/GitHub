#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main()
{
	ifstream readText("text.txt", ios::in);

	if (!readText)
	    {
		ofstream write("text.txt");
	    write << "���� ������ � 5.50\n���� ����� � 5.00\n������ ����� � 6.00\n������ ������� � 5.00\n����� ������ � 4.50\n������ ������ � 3.25\n����� �������� � 4.00\n����� ������� � 6.00\n����� ��������� - 5.49\n������ ������� - 3.27\n�������� ������ - 5.32\n������ ������� - 4.90";
		write.clear();
		write.seekp(0);
	    cerr << "Creating file text.txt"<<endl<<"Please restart the program.";
		exit(1);
		}

	multimap<string, string, greater<string> > studentNames;

	string word;

	while (!readText.eof())
	{
		getline(readText, word);

		for (unsigned i = 0; i < word.size(); i++)
		{
			if (isdigit(word.at(i)))
			{
				string name = word.substr(0,i);
				string grade = word.substr(i,word.size() - i);

			studentNames.insert(pair<string,string>(grade , name));break;

			}
		}
	}

	multimap<string,string>::iterator it = studentNames.begin();

	for (int i = 0 ; i < 10 ; i++)
	{
		cout << it->second << it->first << endl;
		it++;
	}

	return 0;
}
