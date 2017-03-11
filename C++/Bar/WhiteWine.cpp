#include "WhiteWine.h"

// const string for white wine preparation method
static const char * preparationMethod = "I keep it cold and serve it.";

// returns the preparation method of the white wine
const char * WhiteWine::prepare() const
{
	return preparationMethod;
}
