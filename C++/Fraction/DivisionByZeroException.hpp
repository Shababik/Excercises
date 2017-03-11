#pragma once
#include "Exception.h"
class DivisionByZeroException
	: public Exception
{
public:
	DivisionByZeroException() : Exception("Division by zero is invalid.") {}
	DivisionByZeroException(const char * errorMsg) : Exception(errorMsg) {}
	~DivisionByZeroException() {}
};