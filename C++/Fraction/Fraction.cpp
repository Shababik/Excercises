#include "Fraction.h"

/*******************************************/
/*** Fraction class public methods ***/
/*******************************************/

// Factors the fraction if possible
void Fraction::factor()
{
	int greatestCommonDiviser = findGCD(nominator, denominator);
	nominator /= greatestCommonDiviser;
	denominator /= greatestCommonDiviser;
}

// Expands the fraction by the multiplier it receives, 
// throws IllegalFractionActionException
void Fraction::expand(int multiplier)
{ 
	if (multiplier == 0)
	{
		throw ExpansionByZeroException();
	}
	nominator *= multiplier; 
	denominator *= multiplier; 
}


/****************************************************/
/*** Fraction member operator overloading methods ***/
/****************************************************/

/*** operator+= overloading methods ***/

Fraction & Fraction::operator += (int num)
{
	return *this = (*this + num);
}
Fraction & Fraction::operator += (const Fraction & otherFraction)
{
	return *this = (*this + otherFraction);
}


/*** operator-= overloading methods ***/

Fraction & Fraction::operator-= (int num)
{
	return *this = (*this - num);
}
Fraction & Fraction::operator-= (const Fraction & otherFraction)
{
	return *this = (*this - otherFraction);
}


/*** operator*= overloading methods ***/

Fraction & Fraction::operator*= (int num)
{
	return *this = (*this * num);
}
Fraction & Fraction::operator*= (const Fraction & otherFraction)
{
	return *this = (*this * otherFraction);
}


/*** operator/= overloading methods ***/

// throws DivisionByZeroException
Fraction & Fraction::operator/= (int num)
{
	if (num == 0)
	{
		throw DivisionByZeroException();
	}
	return *this = (*this / num);
}
// throws DivisionByZeroException
Fraction & Fraction::operator/= (const Fraction & otherFraction)
{
	if (otherFraction.getNominator() == 0)
	{
		throw DivisionByZeroException();
	}
	return *this = (*this / otherFraction);
}


/*** operator++ overloading methods ***/

Fraction & Fraction::operator++ ()
{
	this->nominator += this->denominator;
	return *this;
}
Fraction Fraction::operator++ (int num)
{
	Fraction oldFraction = Fraction(*this);
	this->nominator += this->denominator;
	return oldFraction;
}


/*** operator-- overloading methods ***/

Fraction & Fraction::operator-- ()
{
	this->nominator -= this->denominator;
	return *this;
}
Fraction Fraction::operator-- (int num)
{
	Fraction oldFraction = Fraction(*this);
	this->nominator -= this->denominator;
	return oldFraction;
}


/*********************************************/
/*** global operator overloading functions ***/
/*********************************************/

/*** operator+ overloading global functions ***/

Fraction operator+ (const Fraction & fraction, int num)
{
	return Fraction(
		fraction.getNominator() + (num * fraction.getDenominator()), 
		fraction.getDenominator());
}
Fraction operator+ (int num, const Fraction & fraction)
{
	return Fraction(
		fraction.getNominator() + (num * fraction.getDenominator()),
		fraction.getDenominator());
}
Fraction operator+ (const Fraction & fraction1, const Fraction & fraction2)
{
	Fraction f1 = Fraction::expand(fraction1, fraction2.getDenominator());
	Fraction f2 = Fraction::expand(fraction2, fraction1.getDenominator());
	return Fraction::factor(Fraction(
		f1.getNominator() + f2.getNominator(), 
		f1.getDenominator()));
}


/*** operator- overloading global functions ***/

Fraction operator- (const Fraction & fraction)
{
	return Fraction(
		fraction.getNominator()*-1,
		fraction.getDenominator());
}
Fraction operator- (const Fraction & fraction, int num)
{
	return Fraction(
		fraction.getNominator() - (num * fraction.getDenominator()),
		fraction.getDenominator());
}
Fraction operator- (int num, const Fraction & fraction)
{
	return Fraction(
		(num * fraction.getDenominator()) - fraction.getNominator(),
		fraction.getDenominator());
}
Fraction operator- (const Fraction & fraction1, const Fraction & fraction2)
{
	Fraction f1 = Fraction::expand(fraction1, fraction2.getDenominator());
	Fraction f2 = Fraction::expand(fraction2, fraction1.getDenominator());
	return Fraction::factor(Fraction(
		f1.getNominator() - f2.getNominator(), 
		f1.getDenominator()));
}


/*** operator* overloading global functions ***/

Fraction operator* (const Fraction & fraction, int num)
{
	return Fraction::factor(Fraction(
		fraction.getNominator() * num,
		fraction.getDenominator()));
}
Fraction operator* (int num, const Fraction & fraction)
{
	return Fraction::factor(Fraction(
		fraction.getNominator() * num,
		fraction.getDenominator()));
}
Fraction operator* (const Fraction & fraction1, const Fraction & fraction2)
{
	return Fraction::factor(Fraction(
		fraction1.getNominator() * fraction2.getNominator(),
		fraction1.getDenominator() * fraction2.getDenominator()));
}


/*** operator/ overloading global functions ***/

// throws DivisionByZeroException
Fraction operator/ (const Fraction & fraction, int num)
{
	if (num == 0)
	{
		throw DivisionByZeroException();
	}
	return Fraction::factor(Fraction(
		fraction.getNominator(),
		fraction.getDenominator() * num));
}
// throws DivisionByZeroException
Fraction operator/ (int num, const Fraction & fraction)
{
	if (fraction.getNominator() == 0)
	{
		throw DivisionByZeroException();
	}
	return Fraction::factor(Fraction(
		fraction.getDenominator() * num,
		fraction.getNominator()));
}
// throws DivisionByZeroException
Fraction operator/ (const Fraction & fraction1, const Fraction & fraction2)
{
	if (fraction2.getNominator() == 0)
	{
		throw DivisionByZeroException();
	}
	return Fraction::factor(Fraction(
		fraction1.getNominator() * fraction2.getDenominator(),
		fraction1.getDenominator() * fraction2.getNominator()));
}


/*** operator== overloading global functions ***/

bool operator== (const Fraction & fraction, int num)
{
	Fraction factoredFraction = Fraction::factor(fraction);
	return (factoredFraction.getDenominator() == 1 
		&& factoredFraction.getNominator() == num);
}
bool operator== (int num, const Fraction & fraction)
{
	Fraction factoredFraction = Fraction::factor(fraction);
	return (factoredFraction.getDenominator() == 1
		&& factoredFraction.getNominator() == num);
}
bool operator== (const Fraction & fraction, const Fraction & otherFraction)
{
	Fraction factoredFraction = Fraction::factor(fraction);
	Fraction otherFactoredFraction = Fraction::factor(otherFraction);
	return (factoredFraction.getNominator() == otherFactoredFraction.getNominator()
		&& factoredFraction.getDenominator() == otherFactoredFraction.getDenominator());
}


/*** operator!= overloading global functions ***/

bool operator!= (const Fraction & fraction, int num)
{
	return !(fraction == num);
}
bool operator!= (int num, const Fraction & fraction)
{
	return !(fraction == num);
}
bool operator!= (const Fraction & fraction, const Fraction & otherFraction)
{
	return !(fraction == otherFraction);
}


/*** operator> overloading global functions ***/

bool operator> (const Fraction & fraction, int num)
{
	Fraction numAsFraction = Fraction(num, 1);
	numAsFraction.expand(fraction.getDenominator());
	return fraction.getNominator() > numAsFraction.getNominator();
}
bool operator> (int num, const Fraction & fraction)
{
	Fraction numAsFraction = Fraction(num, 1);
	numAsFraction.expand(fraction.getDenominator());
	return numAsFraction.getNominator() > fraction.getNominator();
}
bool operator> (const Fraction & fraction, const Fraction & otherFraction)
{
	Fraction f1 = Fraction::expand(fraction, otherFraction.getDenominator());
	Fraction f2 = Fraction::expand(otherFraction, fraction.getDenominator());
	return f1.getNominator() > f2.getNominator();
}


/*** operator>= overloading global functions ***/

bool operator>= (const Fraction & fraction, int num)
{
	return (fraction > num) || (fraction == num);
}
bool operator>= (int num, const Fraction & fraction)
{
	return (num > fraction) || (fraction == num);
}
bool operator>= (const Fraction & fraction, const Fraction & otherFraction)
{
	return (fraction > otherFraction) || (fraction == otherFraction);
}


/*** operator< overloading global functions ***/

bool operator< (const Fraction & fraction, int num)
{
	Fraction numAsFraction = Fraction(num, 1);
	numAsFraction.expand(fraction.getDenominator());
	return fraction.getNominator() < numAsFraction.getNominator();
}
bool operator< (int num, const Fraction & fraction)
{
	Fraction numAsFraction = Fraction(num, 1);
	numAsFraction.expand(fraction.getDenominator());
	return numAsFraction.getNominator() < fraction.getNominator();
}
bool operator< (const Fraction & fraction, const Fraction & otherFraction)
{
	Fraction f1 = Fraction::expand(fraction, otherFraction.getDenominator());
	Fraction f2 = Fraction::expand(otherFraction, fraction.getDenominator());
	return f1.getNominator() < f2.getNominator();
}


/*** operator<= overloading global functions ***/

bool operator<= (const Fraction & fraction, int num)
{
	return (fraction < num) || (fraction == num);
}
bool operator<= (int num, const Fraction & fraction)
{
	return (num < fraction) || (fraction == num);
}
bool operator<= (const Fraction & fraction, const Fraction & otherFraction)
{
	return (fraction < otherFraction) || (fraction == otherFraction);
}


/*** operator<< overloading global functions ***/

std::ostream & operator<<(std::ostream & str, const Fraction & fraction)
{
	str << fraction.getNominator() << "/" << fraction.getDenominator();
	return str;
}
