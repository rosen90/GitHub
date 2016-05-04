#include <iostream>
using namespace std;

string encodeMessage(string msg);
string decodeMessage(string msg);

int main()
{

	string msg = "az sum dqdo mraz";
	cout << msg << endl;
	cout << encodeMessage(msg) << endl;

	cout << decodeMessage(encodeMessage(msg)) << endl;

	return 0;
}

string encodeMessage(string msg)
{
	for(int i = 0; i < (int)msg.size(); i++)
	{
		switch(msg[i])
		{
		case 'z': msg[i] -=23;
			break;
		case 'y': msg[i] -=23;
			break;
		case 'x': msg[i] -=23;
			break;
		case ' ': break;
		default: msg[i] +=3;
		}
	}

	return msg;
}

string decodeMessage(string msg)
{
	for(int i = 0; i < (int)msg.size(); i++)
	{
		switch(msg[i])
		{
		case 'a': msg[i] +=23;
			break;
		case 'b': msg[i] +=23;
			break;
		case 'c': msg[i] +=23;
			break;
		case ' ': break;
		default: msg[i] -=3;
		}
	}

	return msg;
}
