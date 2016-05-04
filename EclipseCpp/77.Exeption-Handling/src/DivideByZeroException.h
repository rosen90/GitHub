#ifndef DIVIDEBYZEROEXCEPTION_H_
#define DIVIDEBYZEROEXCEPTION_H_

#include <stdexcept>
using std::runtime_error;


// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException() :runtime_error("Attempted to divide by zero")
	{
		//empty body
	}

};

#endif
