#pragma once
#include "CalculatorOperation.h"

// Class for division operation
class DivisionOperation :
	public CalculatorOperation
{
public:
	DivisionOperation()
		: CalculatorOperation(requiredParameters, opName, { "/", ":", "div", "divide" }) {};
	~DivisionOperation(){}

	// Returns the quotient of currVal divided by the received parameter.
	// Throws DivisionByZeroException.
	virtual long double calcResult(long double currVal, vector<string> parameters);

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 1;
};

