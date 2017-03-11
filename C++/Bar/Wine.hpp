#pragma once
#include "Drink.h"

// Base class for wine
class Wine : public Drink
{
public:
	// Constructor for wine base class
	Wine(const char* wineName, int year) 
		: Drink(wineName), year(year) {}
	// Destructor
	~Wine() {}

	// Returns the name of the wine
	virtual const char * getName() const;

	// Returns the method of preparation of the wine
	virtual const char * prepare() const = 0;

private:
	// field that holds the year of the wine
	int year;
};

