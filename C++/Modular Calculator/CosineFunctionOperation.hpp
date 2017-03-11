#pragma once
#include "TrigonometricFunctionOperation.h"

// Class for cosine function operation
class CosineFunctionOperation :
	public TrigonometricFunctionOperation
{
public:
	CosineFunctionOperation()
		: TrigonometricFunctionOperation(opName, { "cos", "cosine"}) {};
	~CosineFunctionOperation() {};

	// Applies the cosine function on orgValue.
	inline virtual long double applyFunction(double orgValue) { return cos(orgValue); }

	// Static field that holds the full operation name
	static const string opName;
};
