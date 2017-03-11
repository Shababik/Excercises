#pragma once
#include <vector>
using namespace std;

// Base class for operations
class CalculatorOperation
{
public:
	// Operations base class constructor
	CalculatorOperation(int requiredParameters, const string & operationName, const vector<string> supportedOps)
		: m_requiredParameters(requiredParameters), 
		m_operationName(operationName), 
		m_supportedOps(supportedOps) {}

	// Operations base class destructor
	virtual ~CalculatorOperation() {}

	// Returns the required amount of parameters for the operation
	int getRequiredParameters() { return this->m_requiredParameters; }

	// Returns the full operation name
	string getOperationName() { return this->m_operationName; }

	// Returns true if the operation supports the received syntax, otherwise false
	bool supportsOrientation(string op_string);

	// Returns a string with all of the supported syntaxes for the operation
	string getSupportedOperations();

	//Returns the result of the operation on currVal with the received parameter(s).
	//Throws DivisionByZeroException, ComplexNumberException, InvalidExponentiationException
	//OutOfRangeException, InvalidLogarithmException, InvalidFactorialException, InvalidValueException
	virtual long double calcResult(long double currVal, vector<string> parameters) = 0;
	
protected:
	// Required parameters for the operation
	int m_requiredParameters;

	// The full operation name
	string m_operationName;

	// Vector of all the supported syntaxes for the operation
	vector<string> m_supportedOps;
};

