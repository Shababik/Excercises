#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "CalculatorOperation.h"
#include "Operations.h"
#include "Exception.h"
using namespace std;

/*** Const variables ***/
const int DISPLAY_DOT_PRECISION = 7;
const string QUIT = "quit";
const string SET = "set";
const string HELP = "help";


/*** Function declarations***/

// returns true if param contains a valid number
bool isValidParameter(string & param);

// returns isValidParameter() for each string in params
bool isValidParameters(vector<string> & params);

int main()
{
	// Initializing variables
	long double registerValue = 0;
	vector<CalculatorOperation*> operations =
	{
		new AdditionOperation(), new SubtractionOperation(), new MultiplicationOperation(), new DivisionOperation(),
		new SquareRootOperation(), new ExponentiationOperation(), new NaturalLogarithmOperation(), new FactorialOperation(),
		new SineFunctionOperation(), new CosineFunctionOperation(), new TangentFunctionOperation()
	};
	string input;
	string operationStr;
	string tempParameter;
	vector<string> parameters;

	cout.precision(DISPLAY_DOT_PRECISION+1);
	cout << "Insert operation name (insert 'help' for list of operations, 'quit' to quit)" << endl;

	// Receive operation and parameter(s) until QUIT. Validate both.
	// Try to perform the operation on registerValue using the parameter(s).
	do
	{
		// Getting input and parsing it
		cout << "Current value is: " << registerValue << endl;
		getline(cin, input);
		stringstream ss(input);
		ss >> operationStr;
		while (ss >> tempParameter) 
		{ 
			parameters.push_back(tempParameter); 
		}

		// If parameters are valid, try to look for the operation
		if (isValidParameters(parameters))
		{
			// If operation is HELP, print manual
			if (operationStr.compare(HELP) == 0)
			{
				cout << endl;
				cout << "Setting value (1 parameters)" << endl;
				cout << "Supported operations:\t\t" << "set, <explicit number>" << endl;
				cout << endl;

				// For each operation registered, print details
				for (vector<CalculatorOperation*>::iterator it = operations.begin(); it != operations.end(); ++it)
				{
					cout << (*it)->getOperationName() << " (" << (*it)->getRequiredParameters() << " parameters)" << endl;
					cout << "Supported operations:\t\t" << (*it)->getSupportedOperations() << endl;
					cout << endl;
				}
			}
			// If operation is SET, set value to parameter if exists,
			// otherewise set value to 0.
			else if (operationStr.compare(SET) == 0)
			{
				if (parameters.size() == 0)
				{
					registerValue = 0;
				}
				else
				{
					registerValue = atof(parameters[0].c_str());
				}
			}
			// If an explicit number is typed, set the value to the number.
			else if (isValidParameter(operationStr))
			{
				registerValue = atof(operationStr.c_str());
			}
			// Look in registered operations for an operation that supports
			// the received syntax. If found, try to perform the operation.
			else
			{
				bool found = false;
				for (vector<CalculatorOperation*>::iterator it = operations.begin(); it != operations.end(); ++it)
				{
					// If the operation supports this syntax
					if ((*it)->supportsOrientation(operationStr))
					{
						found = true;
						int requiredParams = (*it)->getRequiredParameters();

						// If the received amount of parameters isn't the required
						// amount of parameters, print error message and receive new input
						if (parameters.size() != requiredParams)
						{
							cout << "This operation accepts " << requiredParams << " parameters." << endl;
							break;
						}

						// Try to set registerValue to the result of the operation using parameters
						try
						{
							registerValue = (*it)->calcResult(registerValue, parameters);
						}
						// If an exception is thrown - print it, receive new input
						catch (Exception e)
						{
							e.print();
						}
						break;
					}
				}
				// If the non-QUIT operation wasn't found, print error message.
				if (!found && !operationStr.compare(QUIT) == 0)
				{
					cout << "This operation is not supported." << endl;
				}
			}
		}
		else // if parameters are not valid
		{
			cout << "One or more of the parameters is invalid." << endl;
		}

		// clear the parameters vector
		parameters.clear();

	} while (!operationStr.compare(QUIT)==0); // while not QUIT, receive new input

	// deleting allocated memory for operations
	for (vector<CalculatorOperation*>::iterator it = operations.begin(); it != operations.end(); ++it)
	{
		delete *it;
	}

	// clearing operations vector
	operations.clear();

	return 0;
}

// returns true if param contains a valid number
bool isValidParameter(string & param)
{
	int signCount = count(param.begin(), param.end(), '-');

	// Return not valid if '-' appears more than once,
	// or not at the beginning of the string.
	if (signCount > 1)
	{
		return false;
	}
	else if (signCount == 1 && param[0] != '-')
	{
		return false;
	}

	// Return not valid if string is empty,
	// or composed of other characters rather than -, digits 1-9
	return (!param.empty() && param.find_first_not_of("-0123456789") == std::string::npos);
}

// returns isValidParameter() for each string in params
bool isValidParameters(vector<string> & params)
{
	for (vector<string>::iterator it = params.begin(); it != params.end(); ++it)
	{
		if (!isValidParameter(*it))
		{
			return false;
		}
	}
	return true;
}