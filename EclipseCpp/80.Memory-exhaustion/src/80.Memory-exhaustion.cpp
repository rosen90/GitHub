//2. Write a program that generates and handles a
//memory-exhaustion exception. Your program should
//loop on a request to create dynamic memory through
//operator new.

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
using std::cerr;
using std::bad_alloc;
using std::exit;

int main()
{
	long double *ptr[100];

	try
	{
		for(int i = 0; i < 100; i++)
		{
			ptr[i] = new long double[50000000];
			cout << "Allocated 50000000 long double int ptr[" << i << "]\n";
		}
	}
	catch(bad_alloc &ex)
	{
		cerr << "Mamory AllocattionFailed.\n";
		exit(EXIT_FAILURE);
	}
	return 0;
}
