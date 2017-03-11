#pragma once
#include "Exception.h"
class InvalidFactorialException
	: public Exception
{
public:
	InvalidFactorialException() 
		: Exception("Factorial operation for the received parameters is illegal.") {}
	InvalidFactorialException(const char * errorMsg) : Exception(errorMsg) {}
	~InvalidFactorialException() {}
};