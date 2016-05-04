/*
 * Statistics.cpp
 *
 *  Created on: 21.09.2014 г.
 *      Author: Kateto
 */

#include "Statistics.h"

Statistics::Statistics()
{
	handsPlayed = 0;
	winGames = 0;
	lostGames = 0;
	creditsIn = 0;
	creditsWon = 0;
}

void Statistics::addHandsPlayed()
{
	handsPlayed += 1;
}
void Statistics::addWinGames()
{

	winGames += 1;
}

void Statistics::addLostGames()
{
	lostGames += 1;
}
void Statistics::addCreditsIn(int value)
{

	creditsIn += value;
}
void Statistics::addCreditsWon(int credits)
{
	creditsWon += credits;
}

int Statistics::getTotalPlayed()
{
	return handsPlayed;
}
int Statistics::getWinGames()
{
	return winGames;
}
int Statistics::getLostGames()
{
	return lostGames;
}
int Statistics::getTotalCreditsIn()
{
	return creditsIn;
}
int Statistics::getTotalCreditsWon()
{
	return creditsWon;
}

void Statistics::printStats()
{
	cout << "\nTotal games played : " << getTotalPlayed();
	cout << "\nTotal win games : " << getWinGames();
	cout << "\nTotal lost games  : " << getLostGames();
	cout << "\nTotal credit in : " << getTotalCreditsIn();
	cout << "\nTotal credit won : " << getTotalCreditsWon();
	cout << endl;
}

void Statistics::readFromFile()
{
	ifstream inFile("Statistics.dat", ios::in);

	if (!inFile)
	{
		cout << "File can not be opened for reading";
	}

	inFile >> handsPlayed >> winGames >> lostGames >> creditsIn >> creditsWon;
}

void Statistics::writeToFile()
{
	ofstream outFile("Statistics.dat", ios::out);

	if (!outFile)
	{
		cout << "File can not be opened writing";
	}

	outFile << getTotalPlayed() << ' ' << getWinGames() << ' ' << getLostGames()
			<< ' ' << getTotalCreditsIn() << ' ' << getTotalCreditsWon() << ' ';
}
