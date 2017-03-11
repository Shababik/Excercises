#pragma once
#include "TrigonometricFunctionOperation.h"

// Class for sine function operation
class SineFunctionOperation :
	public TrigonometricFunctionOperation
{
public:
	SineFunctionOperation()
		: TrigonometricFunctionOperation(opName, { "sin", "sine" }) {};
	~SineFunctionOperation() {};

	// Applies the sine function on orgValue.
	inline virtual long double applyFunction(double orgValue) { return cos(orgValue); }

	// Static field that holds the full operation name
	static const string opName;
};
