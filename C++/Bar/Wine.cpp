#include <iostream>
#include "Wine.h"

// buffer for wine name
const int BUFFER_SIZE = 256;

// returns the formatted name of the wine
const char * Wine::getName() const
{
	char * buffer = new char[BUFFER_SIZE];
	sprintf(buffer, "%s (year %d)", this->drinkName, this->year);
	return buffer;
}
