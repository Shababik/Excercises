#pragma once
#include "CalculatorOperation.h"

// Class for multiplication operation
class MultiplicationOperation :
	public CalculatorOperation
{
public:
	MultiplicationOperation()
		: CalculatorOperation(MultiplicationOperation::requiredParameters, opName, { "*", "x", "mul", "multiply" }) {};
	~MultiplicationOperation(){}

	// Returns the product of currVal multiplied by the received parameter
	inline virtual long double calcResult(long double currVal, vector<string> parameters)
	{ return currVal * atof(parameters.front().c_str()); }

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 1;
};

