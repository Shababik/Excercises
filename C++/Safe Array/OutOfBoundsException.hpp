#pragma once
#include "Exception.h"
class OutOfBoundsException : public Exception
{
public:
	OutOfBoundsException() : Exception() {}
	OutOfBoundsException(const char * errorMsg) : Exception(errorMsg) {}
	~OutOfBoundsException() {}
};