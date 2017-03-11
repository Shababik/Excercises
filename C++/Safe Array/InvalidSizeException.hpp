#pragma once
#include "Exception.h"

class InvalidSizeException : public Exception
{
public:
	InvalidSizeException() : Exception() {}
	InvalidSizeException(const char * errorMsg) : Exception(errorMsg) {}
	~InvalidSizeException() {}
};