#pragma once
#include "CalculatorOperation.h"

// Class for subtraction operation
class SubtractionOperation :
	public CalculatorOperation
{
public:
	SubtractionOperation()
		: CalculatorOperation(requiredParameters, opName, { "-", "sub", "subtract" }) {};
	~SubtractionOperation(){}

	// Returns the difference between currVal and the received parameter
	inline virtual long double calcResult(long double currVal, vector<string> parameters)
	{ return currVal - atof(parameters.front().c_str()); }

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 1;
};

