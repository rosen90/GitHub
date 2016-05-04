#include "Statistics.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

Statistics::Statistics(int numb, int win,int lost, int payout)
{
	this->maxPayout=0;
	setWinningGames(win);
	setLostGames(lost);
	setMaxPayout(payout);
	setNumberOfGames(numb);

}

void Statistics::setMaxPayout(int a)
{
	maxPayout = (a > maxPayout ? a : maxPayout);
}
int Statistics::getMaxPayout()
{
	return maxPayout;
}

void Statistics::printMap()
{
	vector<pair<int,int> > sorted(numberFrequency.begin(), numberFrequency.end());
	sort(sorted.begin(), sorted.end(), pairComparer);
	vector<pair<int,int> >::iterator it;

	int counter = 0;

	cout << "\nStatistics" << endl;
	cout << setw(6) << right <<"number" << setw(11) << right <<"frequency" << endl;

	for (it=sorted.begin(); it != sorted.end(); it++)
	{

		if(counter == 10)
		{
			break;
		}

		cout << setw(6) << right << it->first<< setw(11) << right << it->second << endl;
		counter++;

	}

}

void Statistics::setNumberOfGames(int a)
{
	numberOfGames = a;
}

int Statistics::getNumberOfGames()
{
	return numberOfGames;
}

void Statistics::setWinningGames(int count)
{
	winningGames = count;
}

int Statistics::getWinningGames()
{
	return winningGames;
}

void Statistics::setLostGames(int count)
{
	lostGames = count;
}

int Statistics::getLostGames()
{
	return lostGames;
}

void Statistics::setMap(vector<int> randomNumbers)
{
	for (unsigned i = 0; i < randomNumbers.size(); i++) {
			numberFrequency[randomNumbers[i]]++;
		}

}

map<int,int> Statistics::getMap()
{
	return numberFrequency;
}



Statistics::~Statistics() {

}

bool Statistics::pairComparer(pair<int, int> first, pair<int, int> second)
{
	return first.second > second.second;
}
