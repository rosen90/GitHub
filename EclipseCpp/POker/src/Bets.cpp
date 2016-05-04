/*
 * Bets.cpp
 *
 *  Created on: Sep 19, 2014
 *      Author: vasko
 */

#include "Bets.h"

Bets::Bets()
{
	myBets.insert(pair<int, int>(0, 0));
	myBets.insert(pair<int, int>(1, 1));
	myBets.insert(pair<int, int>(2, 3));
	myBets.insert(pair<int, int>(3, 4));
	myBets.insert(pair<int, int>(4, 6));
	myBets.insert(pair<int, int>(5, 9));
	myBets.insert(pair<int, int>(6, 10));
	myBets.insert(pair<int, int>(7, 20));
	myBets.insert(pair<int, int>(8, 50));
	myBets.insert(pair<int, int>(9, 400));
	myBets.insert(pair<int, int>(10, 600));
	myBets.insert(pair<int, int>(11, 800));


	betsName.insert(pair<int, string>(0, " NONE :( "));
	betsName.insert(pair<int, string>(1, " KINGS_OR_BETTER "));
	betsName.insert(pair<int, string>(2, " TWO_PAIRS "));
	betsName.insert(pair<int, string>(3, "THREE_OF_A_KIND"));
	betsName.insert(pair<int, string>(4, "STRAIGHT"));
	betsName.insert(pair<int, string>(5, "FLUSH"));
	betsName.insert(pair<int, string>(6, "FULL_HOUSE"));
	betsName.insert(pair<int, string>(7, "FOUR_OF_A_KIND"));
	betsName.insert(pair<int, string>(8, "STRAIGHT_FLUSH"));
	betsName.insert(pair<int, string>(9, "WILD_ROYAL_FLUSH"));
	betsName.insert(pair<int, string>(10, "FIVE_OF_A_KIND"));
	betsName.insert(pair<int, string>(11, "NATURAL_ROYAL_FLUSH"));

}

Bets::~Bets()
{
	// TODO Auto-generated destructor stub
}

int Bets::wins(int winType)
{
	int result;
	map<int, int>::iterator it;
	for (it = myBets.begin(); it != myBets.end(); it++)
	{
		if (it->first == winType)
		{
			result =  it->second * BET;
		}
	}
	return result;
}

void Bets::handName(int winType){
	map<int, string>::iterator it;
	for (it = betsName.begin(); it != betsName.end(); it++)
		{
		if (it->first == winType)
				{
					cout<< it->second ;
				}
		}

}
