#pragma once
#include "CalculatorOperation.h"

// Class for logarithm operation
class NaturalLogarithmOperation :
	public CalculatorOperation
{
public:
	NaturalLogarithmOperation()
		: CalculatorOperation(requiredParameters, opName, { "log", "ln" }) {};
	~NaturalLogarithmOperation() {}

	// Returns ln(currVal).
	// Throws InvalidLogarithmException.
	virtual long double calcResult(long double currVal, vector<string> parameters);

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 0;
};