//2. Write a program to check if in a given expression the
//brackets are put correctly. Example of correct
//expression: ((a+b)/5-d). Example of incorrect
//expression: )(a+b)).

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string expression = "(()))(1";

	int counterOpen = 0, counterClose = 0;
	int len = expression.length();
	bool check = true;

//	cout << "Write expression: ";
//	getline (cin, expression);

	for(int i = 0; i <= len - 1; i++)
	{

		if(expression[i] == '(')
		{
			counterOpen++;
		}
		if(expression[i] == ')')
		{
			counterClose++;
		}

		if(counterOpen < counterClose)
		{
			cout << "Incorrect expression";
			check = false;
			break;
		}
		else if((i == len -1) && (counterOpen != counterClose))
		{
			cout << "Incorrect expression";
			check = false;
			break;
		}

	}

	if(check)
	{
		cout << "Correct expression";
	}


	return 0;
}
