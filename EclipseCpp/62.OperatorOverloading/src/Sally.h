#include <iostream>
using namespace std;

#ifndef SALLY_H_
#define SALLY_H_

class Sally
{
	public:
		int num;
		Sally();
		Sally(int);
		Sally operator+(Sally);

};

#endif /* SALLY_H_ */
