#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <vector>


using namespace std;

const string fileBegin = "#include \"PremierNvramDescr.h\" \n\nstatic NVRAM_TABLE_ROW short_table_locations[]= \n{ \n    // DO NOT REMOVE NEXT LINE!!! \n    HAT_GAME_DESCRIPTIONS_SHORT\n\n ";
const string fileEnd = "\n\nstatic NVRAM_TABLE_ROW long_table_locations[]= \n{ \n    // DO NOT REMOVE NEXT LINE!!! \n    HAT_GAME_DESCRIPTIONS_LONG\n\n ";

int countRows = 0;
int midNumber = 16;
int startSeries = 64;
static int donchoNumber = - 16;
string abr;


struct Figure
{
	string figureName;
	int minHits;
	int maxHits;
};

vector<Figure> figures;

void readFigures()
{

	Figure fig;

	int counter = 0;
	int totalFigs;


	cout << "Total figures: ";
	cin >> totalFigs;
	cout << "Game abbreviation: ";
	cin >> abr;

	char c;

	for(int i = 0; i< (int)abr.size(); i++)
	{
		c = abr[i];
		abr[i] = toupper(c);
	}

	cout << "Enter Figure name, Figure minimal hits and figure max hits(e.g-> CAMEL 2 5)" << endl;

	while(counter < totalFigs)
	{

		cin >> fig.figureName >> fig.minHits >> fig.maxHits;

		for(int i = 0; i< (int)fig.figureName.size(); i++)
		{
			c = fig.figureName[i];
			fig.figureName[i] = toupper(c);
		}

		figures.push_back(fig);
		cout << "Figure added" << endl;

		counter++;
		countRows += (fig.maxHits - fig.minHits);

	}
}



int main()
{

	readFigures();

	ofstream outputFile("PremierNvramDescr.cpp", ios::out );
	string numberToWord;

	outputFile << fileBegin;

	for(int i = 0; i < (int)figures.size(); i++)
	{
		for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
		{
			switch(j)
			{
				case 1: numberToWord = "ONE"; break;
				case 2: numberToWord = "TWO"; break;
				case 3: numberToWord = "THREE"; break;
				case 4: numberToWord = "FOUR"; break;
				case 5: numberToWord = "FIVE"; break;
				case 6: numberToWord = "SIX"; break;
				case 7: numberToWord = "SEVEN"; break;
				case 8: numberToWord = "EIGHT"; break;
				case 9: numberToWord = "NINE"; break;

				default: numberToWord = "ERROR"; break;
			}

			if(i == 0 && j == figures[i].minHits)
			{
				donchoNumber += 16;
				outputFile << "	,{NVRAM_" << abr <<"_HITS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}
			else
			{
				donchoNumber += 16;
				outputFile << "	,{NVRAM_" << abr <<"_HITS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}
		}
	}

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_HITS_" << 3 << "THREE" << "_" << "SCATTER"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_HITS_" << "BONUS_FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_TOTAL_" << "FREE_SPINS"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_TOTAL_" << "MULTIPLIER"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


	for(int i = 0; i < (int)figures.size(); i++)
	{
		for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
		{
			switch(j)
			{
				case 1: numberToWord = "ONE"; break;
				case 2: numberToWord = "TWO"; break;
				case 3: numberToWord = "THREE"; break;
				case 4: numberToWord = "FOUR"; break;
				case 5: numberToWord = "FIVE"; break;
				case 6: numberToWord = "SIX"; break;
				case 7: numberToWord = "SEVEN"; break;
				case 8: numberToWord = "EIGHT"; break;
				case 9: numberToWord = "NINE"; break;

				default: numberToWord = "ERROR"; break;
			}

			if(i == 0 && j == figures[i].minHits)
			{
				donchoNumber += 16;
				outputFile << "	,{NVRAM_" << abr <<"_WINS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}
			else
			{
				donchoNumber += 32;
				outputFile << "	,{NVRAM_" << abr <<"_WINS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}

		}
	}



	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr <<"_WINS_" << 3 << "THREE" << "_" << "SCATTER"
			<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr <<"_WINS_" << "BONUS_FREE_SPINS"
			<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr << "HITWIN_CRC"
			<< "\t\t\t\t," << "\t\t" << 4 << "," << "\t\t" << startSeries + 128 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;



	for(int i = 0; i < (int)figures.size(); i++)
	{
		for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
		{
			switch(j)
			{
				case 1: numberToWord = "ONE"; break;
				case 2: numberToWord = "TWO"; break;
				case 3: numberToWord = "THREE"; break;
				case 4: numberToWord = "FOUR"; break;
				case 5: numberToWord = "FIVE"; break;
				case 6: numberToWord = "SIX"; break;
				case 7: numberToWord = "SEVEN"; break;
				case 8: numberToWord = "EIGHT"; break;
				case 9: numberToWord = "NINE"; break;

				default: numberToWord = "ERROR"; break;
			}

			if(i == 0 && j == figures[i].minHits)
			{
				donchoNumber += 4;
				outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}
			else
			{
				donchoNumber += 16;
				outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << j << numberToWord << "_" << figures[i].figureName
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
			}
		}
	}



	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << 3 << "THREE" << "_" << "SCATTER"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << "BONUS_FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_" << "FREE_SPINS"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 16;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_" << "MULTIPLIER"
			<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;



	for(int i = 0; i < (int)figures.size(); i++)
		{
			for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
			{
				switch(j)
				{
					case 1: numberToWord = "ONE"; break;
					case 2: numberToWord = "TWO"; break;
					case 3: numberToWord = "THREE"; break;
					case 4: numberToWord = "FOUR"; break;
					case 5: numberToWord = "FIVE"; break;
					case 6: numberToWord = "SIX"; break;
					case 7: numberToWord = "SEVEN"; break;
					case 8: numberToWord = "EIGHT"; break;
					case 9: numberToWord = "NINE"; break;

					default: numberToWord = "ERROR"; break;
				}

				if(i == 0 && j == figures[i].minHits)
				{
					donchoNumber += 16;
					outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
				else
				{
					donchoNumber += 32;
					outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}

			}
		}



	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << 3 << "THREE" << "_" << "SCATTER"
			<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << "BONUS_FREE_SPINS"
			<< "\t\t\t\t," << "\t\t" << midNumber + 16 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


	donchoNumber += 32;
	outputFile << "	,{NVRAM_" << abr << "HITWIN_CRC"
			<< "\t\t\t\t," << "\t\t" << 4 << "," << "\t\t" << startSeries + 128 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

	outputFile << "\n    // DO NOT REMOVE ABOVE LINE!!!\n};";


	outputFile << fileEnd;

//*************************LONG*************************//

	donchoNumber = - 32;
	midNumber = 32;

	for(int i = 0; i < (int)figures.size(); i++)
		{
			for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
			{
				switch(j)
				{
					case 1: numberToWord = "ONE"; break;
					case 2: numberToWord = "TWO"; break;
					case 3: numberToWord = "THREE"; break;
					case 4: numberToWord = "FOUR"; break;
					case 5: numberToWord = "FIVE"; break;
					case 6: numberToWord = "SIX"; break;
					case 7: numberToWord = "SEVEN"; break;
					case 8: numberToWord = "EIGHT"; break;
					case 9: numberToWord = "NINE"; break;

					default: numberToWord = "ERROR"; break;
				}

				if(i == 0 && j == figures[i].minHits)
				{
					donchoNumber += 32;
					outputFile << "	,{NVRAM_" << abr <<"_HITS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
				else
				{
					donchoNumber += 32;
					outputFile << "	,{NVRAM_" << abr <<"_HITS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
			}
		}

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_HITS_" << 3 << "THREE" << "_" << "SCATTER"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_HITS_" << "BONUS_FREE_SPINS"
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_TOTAL_" << "FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_TOTAL_" << "MULTIPLIER"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


		for(int i = 0; i < (int)figures.size(); i++)
		{
			for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
			{
				switch(j)
				{
					case 1: numberToWord = "ONE"; break;
					case 2: numberToWord = "TWO"; break;
					case 3: numberToWord = "THREE"; break;
					case 4: numberToWord = "FOUR"; break;
					case 5: numberToWord = "FIVE"; break;
					case 6: numberToWord = "SIX"; break;
					case 7: numberToWord = "SEVEN"; break;
					case 8: numberToWord = "EIGHT"; break;
					case 9: numberToWord = "NINE"; break;

					default: numberToWord = "ERROR"; break;
				}

				if(i == 0 && j == figures[i].minHits)
				{
					donchoNumber += 32;
					outputFile << "	,{NVRAM_" << abr <<"_WINS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
				else
				{
					donchoNumber += 64;
					outputFile << "	,{NVRAM_" << abr <<"_WINS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}

			}
		}



		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr <<"_WINS_" << 3 << "THREE" << "_" << "SCATTER"
				<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr <<"_WINS_" << "BONUS_FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr << "HITWIN_CRC"
				<< "\t\t\t\t," << "\t\t" << 4 << "," << "\t\t" << startSeries + 128 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;



		for(int i = 0; i < (int)figures.size(); i++)
		{
			for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
			{
				switch(j)
				{
					case 1: numberToWord = "ONE"; break;
					case 2: numberToWord = "TWO"; break;
					case 3: numberToWord = "THREE"; break;
					case 4: numberToWord = "FOUR"; break;
					case 5: numberToWord = "FIVE"; break;
					case 6: numberToWord = "SIX"; break;
					case 7: numberToWord = "SEVEN"; break;
					case 8: numberToWord = "EIGHT"; break;
					case 9: numberToWord = "NINE"; break;

					default: numberToWord = "ERROR"; break;
				}

				if(i == 0 && j == figures[i].minHits)
				{
					donchoNumber += 4;
					outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
				else
				{
					donchoNumber += 32;
					outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << j << numberToWord << "_" << figures[i].figureName
						<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
				}
			}
		}



		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << 3 << "THREE" << "_" << "SCATTER"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_HITS_" << "BONUS_FREE_SPINS"
					<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_" << "FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 32;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_" << "MULTIPLIER"
				<< "\t\t\t\t," << "\t\t" << midNumber << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;



		for(int i = 0; i < (int)figures.size(); i++)
			{
				for(int j = figures[i].minHits; j <= figures[i].maxHits; ++j)
				{
					switch(j)
					{
						case 1: numberToWord = "ONE"; break;
						case 2: numberToWord = "TWO"; break;
						case 3: numberToWord = "THREE"; break;
						case 4: numberToWord = "FOUR"; break;
						case 5: numberToWord = "FIVE"; break;
						case 6: numberToWord = "SIX"; break;
						case 7: numberToWord = "SEVEN"; break;
						case 8: numberToWord = "EIGHT"; break;
						case 9: numberToWord = "NINE"; break;

						default: numberToWord = "ERROR"; break;
					}

					if(i == 0 && j == figures[i].minHits)
					{
						donchoNumber += 32;
						outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << j << numberToWord << "_" << figures[i].figureName
							<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
					}
					else
					{
						donchoNumber += 64;
						outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << j << numberToWord << "_" << figures[i].figureName
							<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;
					}

				}
			}



		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << 3 << "THREE" << "_" << "SCATTER"
				<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr <<"_LAST_WINS_" << "BONUS_FREE_SPINS"
				<< "\t\t\t\t," << "\t\t" << midNumber + 32 << "," << "\t\t" << startSeries - 64 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;


		donchoNumber += 64;
		outputFile << "	,{NVRAM_" << abr << "HITWIN_CRC"
				<< "\t\t\t\t," << "\t\t" << 4 << "," << "\t\t" << startSeries + 128 << ","<< " HAT_GAME_HEADER_LENGTH_SHORT + " << donchoNumber << "}" << endl;

		outputFile << "\n    // DO NOT REMOVE ABOVE LINE!!!\n};";

		cout << "Completed...";

		outputFile.close();

	return 0;
}

