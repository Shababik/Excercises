#pragma once
#include "Exception.h"
class InvalidLogarithmException
	: public Exception
{
public:
	InvalidLogarithmException()
		: Exception("Logarithm operation for the received parameters is illegal.") {}
	InvalidLogarithmException(const char * errorMsg) : Exception(errorMsg) {}
	~InvalidLogarithmException() {}
};