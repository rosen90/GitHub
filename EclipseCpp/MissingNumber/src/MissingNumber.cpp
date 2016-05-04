#include <iostream>
#include <vector>
using namespace std;

//Algorithm for finding missing number in periodical sequance;

int missingNumber(vector<int> &nums);

int main()
{

	vector<int> sequance;
	sequance.push_back(0);
	sequance.push_back(1);
	sequance.push_back(2);
	sequance.push_back(3);
	sequance.push_back(4);
	sequance.push_back(5);
	sequance.push_back(7);
	sequance.push_back(8);
	sequance.push_back(9);

	cout << "The sequance is ";

	for(int i = 0; i < (int)sequance.size(); i++)
	{
		cout << sequance[i] << " ";
	}

	cout << "\nThe missing number is " << missingNumber(sequance);


	return 0;
}


int missingNumber(vector<int>& nums)
{

	int total;

	total  = ((nums.size())*((nums.size()+1))/2);

	for (int i = 0; i < (int)nums.size(); i++)
	{
		total -= nums[i];
	}

	return total;
}
