#pragma once
#include "CalculatorOperation.h"

// Class for factorial operation
class FactorialOperation :
	public CalculatorOperation
{
public:
	FactorialOperation();
	~FactorialOperation() {}

	// Returns the 'currVal'th factorial.
	// Throws InvalidFactorialException, OutOfRangeException.
	virtual long double calcResult(long double currVal, vector<string> parameters);

	// Static field that holds the full operation name
	static const string opName;

private:
	// Static field that holds the required amount of parameters for the operation
	static const int requiredParameters = 0;

	// A member field that holds n for the highest possible nth factorial to be calculated
	int highestFactorialDivisor;

	// Returns the 'divisor'th factorial
	inline long double factorial(int divisor)
	{ return divisor == 1 ? divisor : divisor * factorial(divisor - 1); }

	// Returns true if the 'num'th factorial can be calculated, otherwise false
	inline bool isFactorialSafe(int num)
	{ return (std::numeric_limits<long double>::max() / num > factorial(num - 1)); }
};