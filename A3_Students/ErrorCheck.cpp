/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "ErrorCheck.h"

// DEFAULT CONSTRUCTOR
ErrorCheck::ErrorCheck()
{
	prompt.clear();
	min = 0;
	max = 0;
}

// NON-DEFUALT CONSTRUCTOR
ErrorCheck::ErrorCheck(string setPrompt, // IN - Used to set the prompt
		               int setMin,       // IN - Used to set the min range
		               int setMax)       // IN - Used to set the max range
{
	prompt = setPrompt;
	min    = setMin;
	max    = setMax;
}

// DECONSTRUCTOR
ErrorCheck::~ErrorCheck()
{
}

/* MUTATORS */

/**************************************************************************
 * METHOD ChangeCheck
 * - This methods changes the prompt, min range, and max range.
 * -> Return - nothing
 *************************************************************************/
void ErrorCheck::ChangeCheck(string newPrompt, int newMin, int newMax)
{
	prompt = newPrompt;
	min    = newMin;
	max    = newMax;
}

/**************************************************************************
 * METHOD ValidateNumInput
 * - This method gets and checks to see if the user input a correct value.
 * 	 It will re-prompt if incorrect (Ranges are passed in).
 * -> Returns - The valid integer.
 *************************************************************************/
int ErrorCheck::ValidateNumInput()
{
	bool invalid; // CALC - Determines if input is valid
	long number;  // IN - User defined input for menu option

	// PROCESSING - Will loop until input is correct
	do
	{
		// PROCESSING - Initializes invalid to false
		invalid = false;

		cout << prompt;

		// PROCESSING - Get and checks to see if a integer was input will
		//		output error message if not
		if (!(cin >> number))
		{
			cout << "\n**** Please input a NUMBER between " << min
				 << " and " << max << " ****\n\n\n";

			// PROCESSING - Clears input buffer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;
		}
		// PROCESSING - Checks to see if integer is in range will output
		//		error message if not
		else if(number < min || number > max)
		{
			// ErrorOutput - Prints formatted out of range message
			ErrorCheck::ErrorOutput(min, max, number);

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalid = true;

		}//END - if (!(cin >> number))

	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;

	return number;
}

/************************************************************************
 * METHOD ErrorOutput
 * - This method combines integers and literals then converts them
 * 	 into strings. Based off which of the two strings are larger determines
 * 	 the width of spaces before the asterisks are output. Special condition
 * 	 error messages are then printed.
 * -> Return - Nothing
 ***********************************************************************/
void ErrorCheck::ErrorOutput(int min, int max, int number)
{
	ostringstream convert;    // CALC - Used to convert an oss to a string
	string        messageOne; // CALC - First error message
	string		  messageTwo; // CALC - Second error message
	int           width;      // CALC - The width for the setw

	// PROCESSING - First message is defined
	convert << "**** The number " << number << " is an invalid entry";

	// PROCESSING - First message is converted to a string
	messageOne = convert.str();

	convert.str("");

	// PROCESSING - Second message is defined
	convert << "**** Please input a number between " << min
			<< " and "                               << max;

	// PROCESSING - Second message is converted to a string
	messageTwo = convert.str();

	// PROCESSING - Conditional used to determine which string will
	//		define the size of width
	width = (messageOne.size() > messageTwo.size()?
			 messageOne.size() : messageTwo.size());

	// OUTPUT - Prints the error messages
	cout << left << endl;
	cout << setw(width) << messageOne << " ****" << endl;
	cout << setw(width) << messageTwo << " ****" << endl << endl << endl;
	cout << right;
}
