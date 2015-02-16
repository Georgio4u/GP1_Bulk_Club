/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "Csoc.h"
#include "header.h"
#include "ErrorCheck.h"
namespace MyName
{
	/**********************************************************************
	 * CONSTANTS
	 * --------------------------------------------------------------------
	 * USED TO SET MENU AND ARRAY SIZES
	 * --------------------------------------------------------------------
	 * SEARCH_MENU : Used to prompt the user
	 * S_SIZE      : Used to set the student array size
	 * C_SIZE      : Used to set the cs1c student array size
	 *********************************************************************/
	const string SEARCH_MENU = "Would you like to search for a Cs1c "
			                   "Student to edit? (enter 0 to exit or "
			                   "1 to continue): ";
	const int S_SIZE = 4;
	const int C_SIZE = 3;

	string response;      // IN - Used to search for a name
	int index;            // CALC - Indexes an array spot
	bool found = false;   // CALC - Used to determine if a name is found
	string changeName;    // IN - Used to change students name
	string changeStanding;// IN - Used to change class standing
	string changePhone;   // IN - Used to change phone number
	int changeAge   = 0;  // IN - Used to change students age
	int changeId    = 0;  // IN - Used to change id number
	int changeScore = 0;  // IN - Used to change score
	int changeDay   = 0;  // IN - Used to change graduation day
	int changeMonth = 0;  // IN - Used to change graduation month
 	int changeYear  = 0;  // IN - Used to change graduation year
	string changeJava;    // IN - Used to change java knowledge
	ErrorCheck test;      // IN - Used to test valid input numbers
	Student studentArr[S_SIZE]; // Used to store students in an array
	Csoc csocArr[C_SIZE];       // Used to store cs1c students in an array
	Header myHeader("Students", 'A', 3); // Used to set the program header
}

using namespace MyName;

/**************************************************************************
 * Students
 * ________________________________________________________________________
 * This program will initialize students into a student class and cs1c
 * 		students class. After being initialized into the program the system
 * 		will "update" Russell Wilson to test all of the the student methods.
 * 		The students list will then be printed to view. There will be an
 * 		option to search cs1c student names to modify their details after.
 * ________________________________________________________________________
 * INPUTS:
 *		response       : Used to search a students name
 *		changeName     : Used to modify a students name
 *		changeStanding : Used to change the students class standing
 *		changePhone    : used to change students phone number
 *		changeAge      : Used to change students age
 *		changeId       : Used to change a students id
 *		changeScore    : Used to change students assignment score
 *		changeDay      : Used to change grad day
 *		changeMonth    : Used to change grad month
 *		changeYear     : Used to change grad year
 *
 * OUTPUTS:
 * 		PrintHeading   : Prints the heading
 * 		PrintColumns   : Used to print the titles of each column
 * 		PrintStudent   : Used to print a students info
 *************************************************************************/
int main()
{

	// METHOD - Prints programs header
	cout << myHeader.ReturnHeader();

	// INITIALIZE - Constructs all of the students (cs and regular)
	cout << "Initializing ALL students...\n\n";
	studentArr[0] = Student("Katy Perry", 'F', 30, 999899, "Freshman",
							4.0, "949-555-1234");
	studentArr[1] = Student("Tom Brady", 'M', 37, 456789, "Sophomore",
							3.23, "714-555-5555");
	studentArr[2] = Student("Russell Wilson", 'M', 26, 876542, "Sophomore",
							3.8, "760-703-1234");
	studentArr[3] = Student("Norm Drapple", 'M', 18, 777744, "Freshman",
							1.10, "213-555-6789");
	csocArr[0] = Csoc("Jim Cramer", 'M', 63, 668899, "Freshman", 3.3,
					  "949-665-1234", 500, "Yes", 12, 5, 2016);
	csocArr[1] = Csoc("Clayton Kershaw", 'M', 29, 156789, "Sophomore", 2.5,
					  "248-555-6543", 700, "No", 11, 5, 2015);
	csocArr[2] = Csoc("Jim Rome", 'M', 40, 876545, "Sophomore", 3.2,
					  "703-703-7654", 800, "Yes", 11, 5, 2015);

	// PRINT - Outputs all of the regular students
	cout << "STUDENTS LIST:\n" << studentArr[0].PrintColumns();
	for(index = 0; index < S_SIZE; index++)
	{
		cout << studentArr[index].PrintStudent();
	}//END - for(index = 0; index < S_SIZE; index++)

	// PRINT - Outputs all of the cs1c students
	cout << endl << "CS1C STUDENTS LIST:\n" <<  csocArr[0].PrintColumns();
	for(index = 0; index < C_SIZE; index++)
	{
		cout << csocArr[index].PrintStudent();
	}//END - for(index = 0; index < C_SIZE; index++)

	cout << endl << endl;

	cout << "Updating " << studentArr[2].GetName() << "'s information..."
			                                          "\n\n";
	// Will change students name
	cout << "Updating name from: " << studentArr[2].GetName() << "...\n";
	studentArr[2].ChangeName("R. Wilson");

	// Will change students age
	cout << "Updating age from: " << studentArr[2].GetAge() << "...\n";
	studentArr[2].ChangeAge(27);

	// Will change students id number
	cout << "Updating id number from: " << studentArr[2].GetId() << "...\n";
	studentArr[2].ChangeId(567892);

	// Will change students class standing
	cout << "Updating class standing from: " << studentArr[2].GetStanding()
		 << "...\n";
	studentArr[2].ChangeStanding("Junior");

	// Will change the students gpa
	cout << "Updating gpa from: " << studentArr[2].GetGpa() << "...\n";
	studentArr[2].ChangeGpa(3.40);

	// Will change the students phone number
	cout << "Updating phone number from: " << studentArr[2].GetPhone()
	     << "...\n";
	studentArr[2].ChangePhone("949-867-5309");

	cout << endl << endl;

	// PRINT - Outputs all of the regular students
	cout << "UPDATED STUDENTS LIST:\n" << studentArr[0].PrintColumns();
	for(index = 0; index < S_SIZE; index++)
	{
		cout << studentArr[index].PrintStudent();
	}//END - for(index = 0; index < S_SIZE; index++)

	cout << endl << endl;

	// PRINT - Outputs all of the cs1c students
	cout << "CS1C STUDENTS LIST:\n" << csocArr[0].PrintColumns();
	for(index = 0; index < C_SIZE; index++)
	{
		cout << csocArr[index].PrintStudent();
	}//END - for(index = 0; index < C_SIZE; index++)

	cout << endl << endl;

	// Used to set the error checking values
	test.ChangeCheck(SEARCH_MENU, 0, 1);

	// LOOP - Will loop until user inputs a 0 to exit
	while(test.ValidateNumInput() != 0)
	{
		// PROMPT - Asks for a student to change information on
		cout << "Enter the name of the student to modify: ";
		getline(cin, response);
		cout << endl;

		index = 0;

		// LOOP - Will search for the input name to compare to those init.
		while(!found && index < C_SIZE)
		{
			// Compare is done here if found bool is changed to true
			if(response == csocArr[index].GetName())
			{
				found = true;
			}
			else
			{
				index++;
			}//END - if(response == csocArr[index].GetName())
		}//END - while(!found && index < C_SIZE)

		// If the student was found the user will be able to modify the
		//	students information
		if(found)
		{
			// PROMPT - Asks to change students name
			cout << "Change Name: ";
			getline(cin, changeName);
			csocArr[index].ChangeName(changeName);
			cout << endl;

			// PROMPT - Asks to change students age
			// Used to set the error checking values
			test.ChangeCheck("Change Age: ", 1, 130);

			// Checks for correct age range then sets age
			changeAge = test.ValidateNumInput();
			csocArr[index].ChangeAge(changeAge);

			// PROMPT - Asks to change students phone number
			cout << "Change Phone Number: ";
			getline(cin, changePhone);
			csocArr[index].ChangePhone(changePhone);
			cout << endl;

			// Prompt - Asks to change student id number
			// Used to set the error checking values
			test.ChangeCheck("Change Id: ", 1, 999999);

			// Tests id range then sets id
			changeId = test.ValidateNumInput();
			csocArr[index].ChangeId(changeId);

			// PROMPT - asks to change students class standing
			cout << "Change Class Standing: ";
			getline(cin, changeStanding);
			csocArr[index].ChangeStanding(changeStanding);
			cout << endl;

			// PROMPT - Asks for a new assignment score
			// Used to set the error checking values
			test.ChangeCheck("Change Assignment Score: ", 0, 1000);

			// checks range then sets score
			changeScore = test.ValidateNumInput();
			csocArr[index].ChangeScore(changeScore);

			// PROMPT - Asks for a Java knowledge
			cout << "Change Java Knowledge: ";
			getline(cin, changeJava);
			csocArr[index].ChangeJava(changeJava);
			cout << endl;

			// PROMPT - Asks for a new graduation date
			cout << "Change Projected Graduation Date (#/#/# format): ";
			cin  >> changeMonth;
			cin.ignore(1);
			cin  >> changeDay;
			cin.ignore(1);
			cin  >> changeYear;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			csocArr[index].ChangeDate(changeDay, changeMonth, changeYear);
			cout << endl << endl;

			// PRINT - Outputs all of the cs1c students
			cout << "UPDATED CS1C STUDENTS LIST:\n"
				 << csocArr[0].PrintColumns();
			for(index = 0; index < C_SIZE; index++)
			{
				cout << csocArr[index].PrintStudent();
			}// END - for(index = 0; index < C_SIZE; index++)
			cout << endl;

		}
		else
		{
			// Error message is student was not found
			cout << "Sorry " << response << " was not found!\n\n";

		}//END - if(found)

		// Used to set the error checking values
		test.ChangeCheck(SEARCH_MENU, 0, 1);

		found = false;

	}//END - while(test.ValidateNumInput() != 0)

	return 0;
}
