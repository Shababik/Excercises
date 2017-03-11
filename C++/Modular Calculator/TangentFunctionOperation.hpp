#pragma once
#include "TrigonometricFunctionOperation.h"

// Class for tangent function operation
class TangentFunctionOperation :
	public TrigonometricFunctionOperation
{
public:
	TangentFunctionOperation() 
		: TrigonometricFunctionOperation(opName, { "tg", "tan", "tangent" }) {};
	~TangentFunctionOperation() {};

	// Applies the tangent function on orgValue.
	inline virtual long double applyFunction(double orgValue) { return tan(orgValue); }

	// Static field that holds the full operation name
	static const string opName;
};
