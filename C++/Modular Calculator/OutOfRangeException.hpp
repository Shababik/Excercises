#pragma once
#include "Exception.h"
class OutOfRangeException
	: public Exception
{
public:
	OutOfRangeException() :
		Exception("The result exceeds the supported range of mathematical values.") {}
	OutOfRangeException(const char * errorMsg) : Exception(errorMsg) {}
	~OutOfRangeException() {}
};