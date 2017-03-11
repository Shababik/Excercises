#pragma once
#include "Exception.h"
class ComplexNumberException
	: public Exception
{
public:
	ComplexNumberException() : 
		Exception("The result of this operation is a complex number and cannot be calculated.") {}
	ComplexNumberException(const char * errorMsg) : Exception(errorMsg) {}
	~ComplexNumberException() {}
};