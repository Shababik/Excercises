#pragma once
#include <iostream>
class Exception
{
public:
	virtual ~Exception() {}
	virtual void print() { std::cout << ((msg != NULL) ? msg : "Empty Exception") << std::endl; }

protected:
	Exception() : msg(NULL) {}
	Exception(const char * errorMsg) { msg = (errorMsg != NULL) ? _strdup(errorMsg) : NULL; };
	char * msg;
};

