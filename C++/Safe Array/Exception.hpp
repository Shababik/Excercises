#pragma once
#include <iostream>
class Exception
{
public:
	inline ~Exception() { if (msg != NULL) { delete[] msg; } }
	virtual void print() { std::cout << ((msg != NULL) ? msg : "Empty Exception") << std::endl; }

protected:
	Exception() : msg(NULL) {}
	Exception(const char * errorMsg) { msg = (errorMsg != NULL) ? _strdup(errorMsg) : NULL; };

private:
	char * msg;
};

