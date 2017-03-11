#include "DivisionOperation.h"
#include "DivisionByZeroException.h"

// Returns the quotient of currVal divided by the received parameter.
// Throws DivisionByZeroException.
long double DivisionOperation::calcResult(long double currVal, vector<string> parameters)
{
	double paramVal = atof(parameters.front().c_str());
	if (paramVal == 0.0)
	{
		throw DivisionByZeroException();
	}
	return currVal / paramVal;
}
