#include <iostream>
#include "Fraction.h"
#include "DivisionByZeroException.h"
#include "ExpansionByZeroException.h"
using namespace std;

#define S (" , ")

char * printCondition(bool condition);

int main()
{
	try
	{
		Fraction f1 = Fraction(2, 3);
		Fraction f2 = Fraction(4, 5);

		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;

		//+, +=, ++
		cout << "f1 + f2 =" << (f1 + f2) << endl;
		cout << "f1 + 3 =" << (f1 + 3) << endl;
		cout << "f1 += f2 =" << (f1 += f2) << endl;		
		cout << "++f2 =" << ++f2 << endl;
		cout << "f2++ =" << f2++ << endl;
		cout << "f2 =" << f2 << endl;
		cout << endl;
		
		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << endl;

		//-, -=, --
		cout << "f1 - f2 =" << (f1 - f2) << endl;
		cout << "f1 - 3 =" << (f1 - 3) << endl;
		cout << "f1 -= f2 =" << (f1 -= f2) << endl;
		cout << "--f2 =" << --f2 << endl;
		cout << "f2-- =" << f2-- << endl;
		cout << "f2 =" << f2 << endl;
		cout << endl;

		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << endl;

		//*, *=
		cout << "f1 * f2 =" << (f1 * f2) << endl;
		cout << "f1 * 3 =" << (f1 * 3) << endl;
		cout << "f1 *= f2 =" << (f1 *= f2) << endl;
		cout << endl;

		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << endl;

		// /, /=
		cout << "f1 / f2 =" << (f1 / f2) << endl;
		cout << "f1 / 3 =" << (f1 / 3) << endl;
		cout << "f1 /= f2 =" << (f1 /= f2) << endl;		
		cout << endl;

		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << endl;

		// ==, !=, >, >=, <, <=
		cout << "f1 == f2 =" << printCondition(f1 == f2) << S << "f1 != f2 =" << printCondition(f1 != f2) << endl;
		cout << "f1 > f2 =" << printCondition(f1 > f2) << S << "f1 >= f2 =" << printCondition(f1 >= f2) << endl;
		cout << "f1 < f2 =" << printCondition(f1 < f2) << S << "f1 <= f2 =" << printCondition(f1 <= f2) << endl;
		cout << endl;
		cout << "f1 == 3 =" << printCondition(f1 == 3) << S << "f1 != 3 =" << printCondition(f1 != 3) << endl;
		cout << "f1 > 3 =" << printCondition(f1 > 3) << S << "f1 >= f2 =" << printCondition(f1 >= 3) << endl;
		cout << "f1 < 3 =" << printCondition(f1 < 3) << S << "f1 <= 3 =" << printCondition(f1 <= 3) << endl;
		cout << endl;

		cout << "Now with the same fraction, expanded." << endl;
		f1 = Fraction(2, 3);
		f2 = Fraction(12, 18);
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << "f1 == f2 =" << printCondition(f1 == f2) << S << "f1 != f2 =" << printCondition(f1 != f2) << endl;
		cout << "f1 > f2 =" << printCondition(f1 > f2) << S << "f1 >= f2 =" << printCondition(f1 >= f2) << endl;
		cout << "f1 < f2 =" << printCondition(f1 < f2) << S << "f1 <= f2 =" << printCondition(f1 <= f2) << endl;
		cout << endl;

		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << endl;
		cout << endl;

		// float()
		cout << "(float)f1 = " << (float)f1 << endl;
		cout << endl;

		// expanding, factoring
		f1.expand(3);
		cout << "f1 expanded by 3 (f1.expand(3))=" << f1 << endl;
		f1.factor();
		cout << "f1 factored (f1.factor())=" << f1 << endl;
		cout << "Fraction::factor(Fraction(635, 1143))=" << Fraction::factor(Fraction(635, 1143)) << endl;
		cout << endl;

		f1 = Fraction(2, 3);
		f2 = Fraction(4, 5);
		Fraction f3 = Fraction(3, 8);
		cout << "Resetting values." << endl;
		cout << "f1 =" << f1 << S << "f2 =" << f2 << S << "f3 =" << f3 << endl;
		cout << endl;

		// Complex expressions
		cout << "-(f1 += f2 * f3) + 7 =" << (-(f1 += f2 * f3) + 7) << endl;
		cout << "f1 != f2 && f2 < ++f3 =" << printCondition(f1 != f2 && f2 < ++f3) << endl;
		cout << endl;

		// Testing with zeroes
		try
		{
			cout << "Fraction(2,0)" << endl;
			Fraction(2, 0);
		}
		catch (DivisionByZeroException e)
		{
			e.print();
		}
		cout << endl;

		try
		{
			cout << "f1/0" << endl;
			f1 / 0;
		}
		catch (DivisionByZeroException e)
		{
			e.print();
		}
		cout << endl;

		try
		{
			f2 = Fraction(0, 7);
			cout << "f2 = Fraction(0, 7)" << endl;
			cout << "f1/f2" << endl;
			f1 / f2;
		}
		catch (DivisionByZeroException e)
		{
			e.print();
		}
		cout << endl;

		try
		{
			cout << "f1.expand(0)" << endl;
			f1.expand(0);
		}
		catch (ExpansionByZeroException e)
		{
			e.print();
		}
		cout << endl;
	}
	catch (Exception e)
	{
		e.print();
	}

	getchar();
	return 0;
}

char * printCondition(bool condition)
{
	return condition ? "true" : "false";
}