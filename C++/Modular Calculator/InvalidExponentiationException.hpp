#pragma once
#include "Exception.h"
class InvalidExponentiationException
	: public Exception
{
public:
	InvalidExponentiationException() 
		: Exception("Exponentiation operation for the received parameters is illegal.") {}
	InvalidExponentiationException(const char * errorMsg) : Exception(errorMsg) {}
	~InvalidExponentiationException() {}
};