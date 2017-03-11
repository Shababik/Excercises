#include "RedWine.h"

// const string for red wine preparation method
static const char * preparationMethod = "I keep it in room temperature (16-18 celcius degrees) and serve it.";

// returns the preparation method of the red wine
const char * RedWine::prepare() const
{
	return preparationMethod;
}
