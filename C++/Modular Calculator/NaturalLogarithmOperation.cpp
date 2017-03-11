#include "NaturalLogarithmOperation.h"
#include "InvalidLogarithmException.h"
#include <math.h>

// Returns ln(currVal).
// Throws InvalidLogarithmException.
long double NaturalLogarithmOperation::calcResult(long double currVal, vector<string> parameters)
{
	if (currVal <= 0.0)
	{
		throw InvalidLogarithmException();
	}
	return log(currVal);
}