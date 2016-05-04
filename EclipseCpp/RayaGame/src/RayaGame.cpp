#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>


using namespace std;

vector<int> convert(string);
void check(vector<int>);

int main() {

	string numbers;
	vector<int> input;

	getline(cin, numbers);

	input = convert(numbers);
	check(input);


	return 0;
}


vector<int> convert(string input)
{
	vector<int> numbers;

	for(int i = 0; i < (int)input.size(); i++)
	{
		char c = input[i];
		if(!isspace(c))
		{
			int temp = c -'0';
			numbers.push_back(temp);
		}
	}

	return numbers;
}

void check(vector<int> input)
{
	bitset<5> constNumbers;
	int emptyBox = 0;
	vector<int> missingBoxes;
	int boxValue = 0;

	for(int i = 1; i < (int)constNumbers.size(); i++)
	{
		for(int j = 0; j < (int)input.size(); j++)
		{
			if(i == input[j])
			{
				constNumbers.set(input[j]);
			}
		}

		if(input[i - 1] == 0)
		{
			emptyBox++;
			boxValue = i;
		}
		if(!constNumbers[i])
		{
			missingBoxes.push_back(i);
		}

	}

	switch(emptyBox)
	{
		case 0: cout << input[0] << " " << input[1]; break;
		case 1: cout << boxValue << " " <<  missingBoxes[0]; break;
		case 2:
		{
			sort(missingBoxes.begin(), missingBoxes.end());
			cout << missingBoxes[0] << " " << missingBoxes[1];
		} break;
	}
}
