#include <iostream>

using namespace std;

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex
{
	public:
		Complex();
		void setRealPart(int); // PROTOTYPE
		void setImaginaryPart(int); // PROTOTYPE
		virtual ~Complex();
	private:
		int m_iRealPart;
		int m_iImaginaryPart;
};

#endif /* COMPLEX_H_ */
