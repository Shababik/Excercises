#pragma once
#include "Wine.h"

// Class for red wine
class RedWine :
	public Wine
{
public:
	// Red wine constructor
	RedWine(char * wineName, int year) 
		: Wine(wineName, year) {}

	// destructor
	~RedWine() {}

	// Returns the method of preparation of the red wine
	virtual const char * prepare() const;
};

