#include <iostream>
#include "Drink.h"

// Empty constructor
Drink::Drink()
{
	this->drinkName = NULL;
}

// Protected constructor for inherited Drink classes
Drink::Drink(const char * drinkName)
{
	if (this->drinkName != NULL)
	{
		delete[] this->drinkName;
	}
	this->drinkName = _strdup(drinkName);
} 

// Destructor
Drink::~Drink()
{
	if (this->drinkName != NULL)
	{
		delete[] this->drinkName;
	}
}
