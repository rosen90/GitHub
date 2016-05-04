#include "Global.h"
#include "Numbers.h"
#include "Balance.h"
#include "PayTable.h"
#include "Statistics.h"
#include <iostream>
#include <fstream>

using namespace std;

bool isWin(int, int);
void saveDataInFile(fstream&,Statistics &);
void getDataFromFile(fstream&, Statistics &);
void printStatistic( ostream&, Statistics &, fstream & );
int checkElement (vector<int> &, int);
bool checkEl(int);

int main() {

	fstream Logs("Statistics.dat", ios::in | ios::out | ios::binary);
	if (!Logs) {
		cerr << "The file coud not be opened !!!";
		exit(1);
	}
	static char c = 'y';
	Balance credits;
	Statistics stats;

	while (c == 'y') {
		getDataFromFile(Logs, stats);
		printStatistic(cout, stats, Logs);
		vector<int> userSelects;

		cout << "Enter numbers from 1 to 80 (press 0 to end input)" << endl;

		int number;
		cin >> number;

		while (number != 0 && userSelects.size() != 10) {
			if (!checkEl(checkElement(userSelects, number))) {
				userSelects.push_back(number);
			}
			PayTable a(userSelects.size());
			a.print();
			cin >> number;
		}

		Numbers numb(userSelects);

		numb.printSelects();

		cout << endl;
		numb.printRandom();

		cout << endl;
		cout << numb.getHits();
		cout << endl;
		PayTable b(userSelects.size());
		b.print();

		credits.setCredit();
		credits.calculateWin(userSelects.size(), numb.getHits(), coefficient);
		stats.setNumberOfGames(stats.getNumberOfGames() + 1);
		if (isWin(userSelects.size(), numb.getHits())) {
			stats.setWinningGames(stats.getWinningGames() + 1);
			stats.setMaxPayout(
					(10 * (coefficient[userSelects.size()][numb.getHits()])));
		} else {
			stats.setLostGames(stats.getLostGames() + 1);
		}
		saveDataInFile(Logs, stats);


//			stats.setMap(numb.getRandoms());
//			stats.printMap();
//
//			cout << endl << "Number of winning games is: " << stats.getWinningGames() << endl;
//			cout << endl << "Number of lost games is: " << stats.getLostGames() << endl;


		numb.clearReset();
		cout << endl;
		//	cout << "MaxPayout is: " <<  stats.getMaxPayout();
		cout << endl;

		cout << "\nYour Credits are: " << credits.getCredit() << endl;
		cout << "For continue playing press \"Y\" " << endl;
		cin >> c;

	}

	return 0;
}
bool isWin(int a, int b) {
	if (coefficient[a][b] > 0)
		return true;
	else
		return false;
}

bool checkEl(int a) {
	if (a == 0)
		return false;
	else
		return true;
}

int checkElement(vector<int> &arr, int b) {
	int count = 0;
	for (unsigned i = 0; i < arr.size(); i++) {
		if (arr[i] == b) {
			arr.erase(arr.begin() + i);
			count++;
		}
	}
	return count;
}

void saveDataInFile(fstream &insertInFile, Statistics &stat) {

	insertInFile.seekp(0);
	insertInFile.write(reinterpret_cast<const char *> (&stat),
			sizeof(Statistics));

}
void getDataFromFile(fstream &file, Statistics &stat) {
	file.seekg(0);
	file.read(reinterpret_cast<char *> (&stat), sizeof(Statistics));
	stat.setLostGames(stat.getLostGames());
	stat.setWinningGames(stat.getWinningGames());
	stat.setNumberOfGames(stat.getNumberOfGames());
	stat.setMaxPayout(stat.getMaxPayout());

}
void printStatistic(ostream &output, Statistics &stat, fstream &file) {
	file.seekg(0);
	file.read(reinterpret_cast<char *> (&stat), sizeof(Statistics));
	output << setw(5) << right << "Games" << setw(7) << right << "Wins"
			<< setw(8) << right << "Loses" << setw(13) << right << "Max Payout"
			<< endl;

	output << setw(5) << right << stat.getNumberOfGames() << setw(7) << right
			<< stat.getWinningGames() << setw(8) << right
			<< stat.getLostGames() << setw(13) << right << stat.getMaxPayout()
			<< endl;
}

