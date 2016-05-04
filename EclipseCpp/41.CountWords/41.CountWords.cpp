//8. Write a program that reads a string from the console and
//lists all the different words in the string with information
//how many times each word is found.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string str = "ASCII stands for for American American ";

	string words;

	int wordCount=0;
	int oldSpace = 0;
	int space = str.find(" ");



	 stringstream ss (str);
	 string word;

	 while ( ss >> word )
	 {
		 wordCount++;
	 }

	 string arrayOfWords[wordCount];
	 int arrayCounter[wordCount] = {0};
	 string noRepeated[wordCount];

	 for (int i = 0; i < wordCount; i++)
	 {
		 words = str.substr(oldSpace, space - oldSpace);
		 oldSpace = space + 1;
		 space = str.find_first_of(" ", space + 1);

		 arrayOfWords[i] = words;

		 for(int j = 0; j < wordCount; j++)
		 {
			 if(arrayOfWords[i] == arrayOfWords[j])
			 {
				 arrayCounter[j]++;
			 }
		 }


	 }


//	 for(int i = 0; i < wordCount; i++)
//	 {
//		 if(arrayOfWords[i] != arrayOfWords[i+1])
//		 {
//			noRepeated[i] = arrayOfWords[i];
//		 }
//	 }

	 for(int i = 0; i < wordCount; i++)
	 {

			 cout << arrayOfWords[i] << " " << arrayCounter[i] <<  endl;

	 }


	cout <<"The number of words is " << wordCount;

	return 0;
}
