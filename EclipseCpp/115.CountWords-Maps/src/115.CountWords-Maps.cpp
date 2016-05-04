#include <iostream>
#include <map>
using namespace std;

typedef multimap <string, less<string> > strMap;

int main()
{

	string str = "Vasko vasko kaza na nego";

	strMap countWords;



	cout << countWords.count("vasko");


	return 0;
}
