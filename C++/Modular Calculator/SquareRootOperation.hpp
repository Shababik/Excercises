#pragma once
#include "CalculatorOperation.h"

// Class for square root operation
class SquareRootOperation :
	public CalculatorOperation
{
public:
	SquareRootOperation()
		: CalculatorOperation(requiredParameters, opName, { "sqrt", "V", "root"}) {};
	~SquareRootOperation(){}

	// Returns the square root of currVal.
	// Throws ComplexNumberException.
	virtual long double calcResult(long double currVal, vector<string> parameters);

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 0;
};