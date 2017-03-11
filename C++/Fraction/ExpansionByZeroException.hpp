#pragma once
#include "Exception.h"
class ExpansionByZeroException
	: public Exception
{
public:
	ExpansionByZeroException() : Exception("Multiplier for Fraction expansion cannnot be zero.") {}
	ExpansionByZeroException(const char * errorMsg) : Exception(errorMsg) {}
	~ExpansionByZeroException() {}
};