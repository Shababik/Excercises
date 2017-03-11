#pragma once
#include "CalculatorOperation.h"

// Base class for trigonometric function operations
class TrigonometricFunctionOperation :
	public CalculatorOperation
{
public:
	TrigonometricFunctionOperation(string operationName, vector<string> supportedOps)
		: CalculatorOperation(requiredParameters, operationName, supportedOps) {};
	~TrigonometricFunctionOperation() {};

	// Returns the result of applying the trigonometric function on currVal (degrees)
	inline virtual long double calcResult(long double currVal, vector<string> parameters)
	{ return applyFunction(currVal*PI / 180); }
	
	// Applies the trigonometric function on orgValue.
	virtual long double applyFunction(double orgValue) = 0;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 0;

	// Static field that holds the mathematical constant PI
	const double PI = 3.14159265358979323846;
};
