#include "SquareRootOperation.h"
#include "ComplexNumberException.h"
#include <math.h>

// Returns the square root of currVal.
// Throws ComplexNumberException.
long double SquareRootOperation::calcResult(long double currVal, vector<string> parameters)
{
	if (currVal < 0.0)
	{
		throw ComplexNumberException();
	}
	return sqrt(currVal);
}

