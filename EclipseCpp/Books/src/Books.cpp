#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool pairComparer(pair<int,int>, pair<int,int>);

int main()
{
	multimap<int, int, greater<int> > books;
	int counter = 0;
	int a, b;


	while(counter < 4)
	{
		cin >> a >> b;
		books.insert(pair<int,int>(a,b));
		counter++;
	}

	vector<pair<int,int> > sorted(books.begin(), books.end());
	sort(sorted.begin(), sorted.end(), pairComparer);

	for(vector<pair<int,int> >::iterator it = sorted.begin(); it != sorted.end(); it++)
	{

	}

	return 0;
}

bool pairComparer(pair<int, int> first, pair<int, int> second)
{
	return first.second > second.second;
}
