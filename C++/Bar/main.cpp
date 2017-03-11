#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include "Drink.h"
#include "Beer.h"
#include "Wine.h"
#include "WhiteWine.h"
#include "RedWine.h"
using namespace std;

/*** constants ***/
const int SHELF_SIZE = 11;

const int OPTION_INVALID = -1;
const int OPTION_LIST = 0;
const int OPTION_PREPARE = 99;
const int OPTION_LEAVE = 100;

const char * const OPENING_MESSAGE =
"What can I get you? ";
const char * const LIST_OPTIONS =
"(0 - list options)";
const char * const HOW_DID_YOU_PREPARE =
"(99)\tHow did you prepare my last drink?";
const char * const LEAVE_THE_BAR =
"(100)\tLeave the bar";
const char * const YOU_DID_NOT_ORDER =
"You didn't order anything yet.";
const char * const BAR_IS_CLOSED =
"Bar is closed. Good night.";
const char * const INVALID_MESSAGE =
"Choice is invalid.";


/*** Function declarations ***/
int getAndValidateInput();

int main()
{
	// Initializing stock
	Drink ** stock = new Drink* [SHELF_SIZE];
	stock[0] = new Beer("Maccabi");
	stock[1] = new Beer("Tuborg");
	stock[2] = new Beer("Heineken");
	stock[3] = new Beer("Carlsberg");
	stock[4] = new WhiteWine("Carmel Emerald Riesling", 1986);
	stock[5] = new WhiteWine("Golan Smadar", 1989);
	stock[6] = new WhiteWine("Yarden Chardonnay", 1997);
	stock[7] = new RedWine("Chianti", 1997);
	stock[8] = new RedWine("Yarden Mount Hermon Red", 1994);
	stock[9] = new RedWine("Yarden Cabernet Sauvignon", 1997);
	stock[10] = new RedWine("Chadeau Margot", 1997);

	// Initializing variables
	Drink * lastChosenDrink = NULL;
	int userChoice = OPTION_INVALID;
	bool requestFulfilled = true;

	do
	{
		// if request was fulfilled or user choice is OPTION_INVALID,
		// print opening message and mark request not fulfilled
		if (requestFulfilled || userChoice == OPTION_INVALID)
		{
			std::cout << OPENING_MESSAGE << LIST_OPTIONS << std::endl;
			requestFulfilled = false;
			continue;
		}
		// if user choice is OPTION_LIST, print the stock
		else if (userChoice == OPTION_LIST)
		{
			std::cout << LIST_OPTIONS << std::endl;

			for (int i = 0; i < SHELF_SIZE; ++i)
			{
				std::cout << "(" << (i+1) << ")\t" << stock[i]->getName() << std::endl;
			}

			std::cout << HOW_DID_YOU_PREPARE << std::endl;
			std::cout << LEAVE_THE_BAR << std::endl;
		}
		// if user choice is between 1 and last index on the shelf,
		// serve the selected drink from the stock
		else if (userChoice >= 1 && userChoice <= SHELF_SIZE)
		{
			lastChosenDrink = stock[userChoice - 1];
			std::cout << "One " << lastChosenDrink->getName() << " coming up." << std::endl;
		}
		// if user choice is OPTION_PREPARE, print the preparation
		// method for the last drink that was ordered, or print error msg
		else if (userChoice == OPTION_PREPARE)
		{
			if (lastChosenDrink == NULL)
			{
				std::cout << YOU_DID_NOT_ORDER << std::endl;
			}
			else
			{
				std::cout << lastChosenDrink->prepare() << std::endl;
			}
		}
		// if user choice doesn't match any option,
		// mark request not fulfilled
		else
		{
			requestFulfilled = false;
			std::cout << INVALID_MESSAGE << std::endl;
			continue;
		}
		// mark request was fulfilled in case of not continuing
		requestFulfilled = true;

	} while (requestFulfilled || ((userChoice = getAndValidateInput()) != OPTION_LEAVE));
	// As long as a request was fulfilled and the input wasn't OPTION_LEAVE

	// print closing message
	std::cout << BAR_IS_CLOSED << std::endl;

	// free allocated memory
	delete[] stock;
	delete[] lastChosenDrink;

	getchar();
	return 0;
}

int getAndValidateInput()
{
	string input;
	getline(cin, input);

	// Return the int value of user choice if input is not empty,
	// and is composed only of the characters '1'-'9'
	if (!input.empty() && input.find_first_not_of("0123456789") == std::string::npos)
	{
		return atoi(input.c_str());
	}

	// return OPTION_INVALID
	return OPTION_INVALID;
}