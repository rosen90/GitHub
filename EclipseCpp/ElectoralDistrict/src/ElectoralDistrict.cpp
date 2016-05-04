#include <iostream>
#include "State.h"

using namespace std;

int main()
{

	string name = "Sofia";
	int allVotes = 1500;
	int numberOfParties = 7;
	int partialVotes[] = {150, 238, 45, 302, 175, 343, 247};
	string partiesNames[] = {"GERB", "BSP", "DPS", "ABV", "ATAKA", "RB", "PF"};

	State st(name, allVotes, numberOfParties, partialVotes, partiesNames);
	st.sortResultsByName();
	//st.sortResultsByPercent();
	cout << "---Results---" << endl;
	st.printResults();


	return 0;
}
