#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <map>
#include <vector>

using namespace std;

class Statistics
{
public:
	Statistics(int=0, int=0,int=0,int=0);
	virtual ~Statistics();
	void setMap(vector<int>);
	void printMap();
	map<int,int> getMap();
	int getMaxPayout();
	void setMaxPayout(int);
	void setWinningGames(int);
	int getWinningGames();
	void setLostGames(int);
	int getLostGames();
	void setNumberOfGames(int);
	int getNumberOfGames();

private:
	int numberOfGames;
	int winningGames;
	int lostGames;
	int maxPayout;
	map<int, int> numberFrequency;
	static bool pairComparer(pair<int,int> first, pair<int,int> second);

};

#endif
