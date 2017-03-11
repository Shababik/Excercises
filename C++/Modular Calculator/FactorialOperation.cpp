#include "FactorialOperation.h"
#include "InvalidFactorialException.h"
#include "OutOfRangeException.h"
#include <math.h>

// Initializes fields and calculates n for the highest possible nth factorial to be calculated
FactorialOperation::FactorialOperation() 
	: CalculatorOperation(requiredParameters, opName, { "!", "fact", "factorial"})
{
	int i = 2;
	while (isFactorialSafe(i))
	{
		i++;
	}
	this->highestFactorialDivisor = --i;
}

// Returns the 'currVal'th factorial.
// Throws InvalidFactorialException, OutOfRangeException.
long double FactorialOperation::calcResult(long double currVal, vector<string> parameters)
{
	int result = 0;
	if (currVal < 1 || currVal - static_cast<int>(currVal) != 0.0)
	{
		throw InvalidFactorialException();
	}
	if (currVal > highestFactorialDivisor)
	{
		throw OutOfRangeException();
	}
	return factorial(currVal);
}