#include <iostream>
#include "Beer.h"

// const string for beer preparation method
static const char * preparationMethod =
		"I poured it into your glass and served it.";

// returns the preparation method of the beer
const char * Beer::prepare() const
{
	return preparationMethod;
}
