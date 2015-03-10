#include "Date.h"
#include "OtherFunctions.h"

/*************************************************************************
 *
 * FUNCTION GetAndCheckInt
 *_________________________________________________________________________
 * This function will check for wrong input entered by the user, only
 * number range passed in should be correct input.
 *_________________________________________________________________________
 * Pre-Conditions
 * 	must have two values as parameters
 *
 * Post-Conditions
 * 	This function will return the pick to main. if not valid, will return
 * 	a -1.
 *************************************************************************/
float GetAndCheckInt(int int1, //IN -  lowest allowable parameter for
		//      correct values that need to be
		//      error checked.
		int int2) //IN -  highest allowable parameter for
					//      correct values that need to be
					//      error checked.
{

	ostringstream buffer; // CALC - used for spacing purposes
	bool inputOk;         // CALC - error checking bool
	float pick;           // OUT  - will output a correct number

	//OUT - error checking command
	pick = 0;
	inputOk = false;

	// if the number is a character
	if (!(cin >> pick))
	{
		cout << endl;
		cout << "**** Please input a NUMBER between " << int1 << " and " << int2
				<< "       ****";
		// wrong input will return an -1
		pick = -1;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl << endl;

	}

	else
	{

		// this sets bool to true
		inputOk = (pick >= int1 && pick < int2 + 1);

		// if the number is not a valid entry
		if (!inputOk)
		{
			//OUTPUT
			cout << left;
			cout << endl;
			buffer << "**** The number " << pick;
			cout << buffer.str() << setw(49 - buffer.str().length());
			//cout << buffer.width();
			cout << left << " is not a valid entry" << "****";
			cout << endl;
			cout << "**** Please input a NUMBER between ";
			cout << int1 << " and " << setw(6) << left << int2 << "  ****";
			cout << endl << endl;
			buffer.str("");
			// wrong input will return an -1
			pick = -1;

		}

	}
	// RETURN STATEMENT
	return pick;
}

