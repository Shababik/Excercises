#pragma once
#include "Exception.h"
class MemoryAllocationException : public Exception
{
public:
	MemoryAllocationException() : Exception() {}
	MemoryAllocationException(const char * errorMsg) : Exception(errorMsg) {}
	~MemoryAllocationException() {}
};