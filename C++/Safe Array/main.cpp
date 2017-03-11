#include <iostream>
#include "SafeArray.h"
#include "Exception.h"
int main()
{
	try
	{
		// Demonstrating supported SafeArray usages with ints
		SafeArray<int> intArr(10);
		intArr[0] = 2;
		int a = intArr[0];
		int & b = intArr[0];
		int * int_p = intArr + 9;
		int_p = &intArr[0];
		int_p = intArr;
		*int_p = 44;

		// Demonstrating supported SafeArray usages with strings
		SafeArray<char*> stringArr(10);
		stringArr[0] = "Hello";
		stringArr[1] = "My";
		stringArr[2] = "Name";
		stringArr[3] = "Is";
		stringArr[4] = "Kishkashta";
		stringArr[5] = stringArr[0];

		// Demonstrating common usage of SafeArray<char*>
		// Iterating from p = stringArr
		char ** string_p = stringArr;
		while (*string_p != NULL)
		{
			std::cout << *string_p << " ";
			string_p++;
		}
		std::cout << std::endl;

		// Demonstrating common usage of SafeArray<char*>
		// Iterating from p = stringArr + 3
		string_p = stringArr + 3;
		while (*string_p != NULL)
		{
			std::cout << *string_p << " ";
			string_p++;
		}
	}
	catch (Exception e)
	{
		e.print();
	}

	getchar();
	return 0;
}