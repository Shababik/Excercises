#pragma once
#include "Wine.h"

// Class for white wine
class WhiteWine :
	public Wine
{
public:
	// White wine constructor
	WhiteWine(char * wineName, int year) 
		: Wine(wineName, year) {}

	// destructor
	~WhiteWine() {}

	// Returns the method of preparation of the white wine
	virtual const char * prepare() const;
};