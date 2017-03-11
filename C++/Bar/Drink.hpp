#pragma once
class Drink
{
	// Base class for drink
public:
	// Empty constructor
	Drink();
	// Destructor
	virtual ~Drink();

	// Returns the name of the drink
	virtual const char * getName() const { return this-> drinkName; }

	// Returns the method of preparation of the drink
	virtual const char * prepare() const = 0;

protected:
	// Protected constructor for inherited Drink classes
	Drink (const char * name);

	// field that holds the name of the drink
	char * drinkName;
};

