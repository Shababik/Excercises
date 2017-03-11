#include "CalculatorOperation.h"

// Returns true if the operation supports the received syntax, otherwise false
bool CalculatorOperation::supportsOrientation(string op_string)
{
	for (unsigned i = 0; i < m_supportedOps.size(); i++)
	{
		if (op_string.compare((m_supportedOps[i])) == 0)
		{
			return true;
		}
	}
	return false;
}

// Returns a string with all of the supported syntaxes for the operation
string CalculatorOperation::getSupportedOperations()
{
	string cat = "";
	for (vector<string>::iterator it = m_supportedOps.begin(); it != m_supportedOps.end(); ++it)
	{
		cat += *it + ", ";
	}
	cat[cat.size() - 2]=' ';
	return cat;
}