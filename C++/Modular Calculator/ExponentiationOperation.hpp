#pragma once
#include "CalculatorOperation.h"

// Class for exponentiation operation"
class ExponentiationOperation :
	public CalculatorOperation
{
public:
	ExponentiationOperation()
		: CalculatorOperation(requiredParameters, opName, { "^", "pow", "power" }) {};
	~ExponentiationOperation(){}

	// Returns the result of the base currVal exponentiated by the received parameter exponent.
	// Throws InvalidExponentiationException, OutOfRangeException.
	virtual long double calcResult(long double currVal, vector<string> parameters);

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 1;
};