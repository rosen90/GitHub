#ifndef STATE_H_
#define STATE_H_

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class State
{

public:
	State(string, int, int, int [], string []);
	virtual ~State();

	void printResults();
	void fillResults();
	double convertToPercent(int);
	void sortResultsByName();
	void sortResultsByPercent();

private:
	//string *name;
	char *name;
	int allVotes;
	int numberOfParies;

	int *partialVotes;
	//string *partiesNames;

	char **partiesNames;

	vector< pair<string, double> > finalResults;
};


#endif /* STATE_H_ */
