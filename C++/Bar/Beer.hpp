#pragma once
#include "Drink.h"

// Class for beer
class Beer : public Drink
{
public:
	// Beer constructor
	Beer(const char * beerName) 
		: Drink(beerName) {}

	// destructor
	~Beer() {}

	// Returns the method of preparation of the beer
	virtual const char * prepare() const;
};

