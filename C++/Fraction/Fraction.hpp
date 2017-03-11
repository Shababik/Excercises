#pragma once
#include <iostream>
#include "DivisionByZeroException.h"
#include "ExpansionByZeroException.h"

//TODO exceptions (DivisionByZeroException, IllegalFractionActionException)
class Fraction
{
public:
	/*******************************************/
	/*** c'tors and d'tors ***/
	/*******************************************/

	// Regular c'tor, throws DivisionByZeroException
	Fraction(int nominator, int denominator) 
		: nominator(nominator), denominator(denominator) 
	{ if (denominator == 0) throw DivisionByZeroException(); }

	// Conversion c'tor from int
	Fraction(int num)
		: nominator(num), denominator(1) {}

	// Copy c'tor from another Fraction object
	Fraction(const Fraction & otherFraction)
		: nominator(otherFraction.nominator), 
		denominator(otherFraction.denominator) {}

	// Default d'tor
	~Fraction() {}


	/*******************************************/
	/*** public methods ***/
	/*******************************************/

	// Returns the fraction's nominator
	int getNominator() const { return nominator; }

	// Returns the fraction's denominator
	int getDenominator() const { return denominator; }

	// Factors the fraction if possible
	void factor();

	// Expands the fraction by the multiplier it receives, 
	// throws IllegalFractionActionException
	void expand(int multiplier);


	/*******************************************/
	/*** member operator overloading methods ***/
	/*******************************************/

	// Conversion to float operator overloading 
	inline operator float() const { return ((float)nominator) / denominator; }

	// Assignment operator overloading
	inline Fraction & operator= (const Fraction & otherFraction) { 
		this->nominator = otherFraction.nominator; 
		this->denominator = otherFraction.denominator; 
		return *this;
	}

	/*** operator+= overloading global functions ***/

	Fraction & operator+= (int num);
	Fraction & operator+= (const Fraction & otherFraction);

	/*** operator-= overloading global functions ***/

	Fraction & operator-= (int num);
	Fraction & operator-= (const Fraction & otherFraction);

	/*** operator*= overloading global functions ***/

	Fraction & operator*= (int num);
	Fraction & operator*= (const Fraction & otherFraction);

	/*** operator/= overloading global functions ***/

	// throws DivisionByZeroException
	Fraction & operator/= (int num);
	// throws DivisionByZeroException
	Fraction & operator/= (const Fraction & otherFraction);

	/*** operator++ overloading global functions ***/

	Fraction & operator++ ();
	Fraction operator++ (int num);

	/*** operator-- overloading global functions ***/

	Fraction & operator-- ();
	Fraction operator-- (int num);


	/*******************************************/
	/*** static public methods ***/
	/*******************************************/

	// Same as factor() method
	inline static Fraction factor(Fraction fraction) 
	{ fraction.factor(); return fraction; }

	// Same as expand() method
	//throws IllegalFractionActionException
	inline static Fraction expand(Fraction fraction, int multiplier) 
	{ fraction.expand(multiplier); return fraction; }

private:
	int nominator;
	int denominator;

	// returns the greatest common diviser of two ints
	inline int findGCD(int a, int b) { return b == 0 ? a : findGCD(b, a % b); }
};


/*********************************************/
/*** global operator overloading functions ***/
/*********************************************/

/*** operator+ overloading global functions ***/

Fraction operator+ (const Fraction & fraction, int num);
Fraction operator+ (int num, const Fraction & fraction);
Fraction operator+ (const Fraction & fraction1, const Fraction & fraction2);


/*** operator- overloading global functions ***/
Fraction operator- (const Fraction & fraction);
Fraction operator- (const Fraction & fraction, int num);
Fraction operator- (int num, const Fraction & fraction);
Fraction operator- (const Fraction & fraction1, const Fraction & fraction2);


/*** operator* overloading global functions ***/

Fraction operator* (const Fraction & fraction, int num);
Fraction operator* (int num, const Fraction & fraction);
Fraction operator* (const Fraction & fraction1, const Fraction & fraction2);


/*** operator/ overloading global functions ***/

// throws DivisionByZeroException
Fraction operator/ (const Fraction & fraction, int num);
// throws DivisionByZeroException
Fraction operator/ (int num, const Fraction & fraction);
// throws DivisionByZeroException
Fraction operator/ (const Fraction & fraction1, const Fraction & fraction2);


/*** operator== overloading global functions ***/

bool operator== (const Fraction & fraction, int num);
bool operator== (int num, const Fraction & fraction);
bool operator== (const Fraction & fraction, const Fraction & otherFraction);


/*** operator!= overloading global functions ***/

bool operator!= (const Fraction & fraction, int num);
bool operator!= (int num, const Fraction & fraction);
bool operator!= (const Fraction & fraction, const Fraction & otherFraction);


/*** operator> overloading global functions ***/

bool operator> (const Fraction & fraction, int num);
bool operator> (int num, const Fraction & fraction);
bool operator> (const Fraction & fraction, const Fraction & otherFraction);


/*** operator>= overloading global functions ***/

bool operator>= (const Fraction & fraction, int num);
bool operator>= (int num, const Fraction & fraction);
bool operator>= (const Fraction & fraction, const Fraction & otherFraction);


/*** operator< overloading global functions ***/

bool operator< (const Fraction & fraction, int num);
bool operator< (int num, const Fraction & fraction);
bool operator< (const Fraction & fraction, const Fraction & otherFraction);


/*** operator<= overloading global functions ***/

bool operator<= (const Fraction & fraction, int num);
bool operator<= (int num, const Fraction & fraction);
bool operator<= (const Fraction & fraction, const Fraction & otherFraction);


/*** operator<< overloading global functions ***/

std::ostream & operator<<(std::ostream & str, const Fraction & fraction);
