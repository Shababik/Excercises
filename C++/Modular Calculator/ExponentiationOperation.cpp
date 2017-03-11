#include "ExponentiationOperation.h"
#include "InvalidExponentiationException.h"
#include "OutOfRangeException.h"
#include <math.h>

// Returns the result of the base currVal exponentiated by the received parameter exponent.
// Throws InvalidExponentiationException, OutOfRangeException.
long double ExponentiationOperation::calcResult(long double currVal, vector<string> parameters)
{
	double result = 0;;
	double paramVal = atof(parameters.front().c_str());
	if ((currVal < 0.0 && (paramVal - static_cast<int>(paramVal) != 0.0))
		|| (currVal == 0.0 && paramVal == 0.0)
		|| (currVal ==0 && paramVal<0))
	{
		throw InvalidExponentiationException();
	}
	result = pow(currVal, paramVal);
	if (errno == ERANGE)
	{
		throw OutOfRangeException();
	}
	return result;
}