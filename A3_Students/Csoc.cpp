/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "Csoc.h"

// DEFUALT CONSTRUCTOR
Csoc::Csoc(): Student()
{
	asScore = 0;
	java.clear();
}

// NON-DEFUALT CONSTRUCTOR
Csoc::Csoc(string setName,     // Used to set the students name
		   char setGender,     // Used to set the students gender
		   int setAge,         // Used to set the student age
		   int setId,          // Used to set the students id
		   string setStanding, // Used to set the students class standing
		   float setGpa,       // Used to set the students gpa
		   string setPhone,    // Used to set the students phone number
           int    setScore,    // Used to set the students assignment score
		   string setJava,     // Used to set if student knows java
		   int setDay,         // Used to set graduation day
		   int setMonth,       // Used to set graduation month
		   int setYear)        // Used to set graduation year

		   // Used to set the base class object
		   :Student(setName,     // Used to set the students name
			        setGender,   // Used to set the students gender
			        setAge,      // Used to set the student age
			        setId,       // Used to set the students id
			        setStanding, // Used to set the students class stan
			        setGpa,      // Used to set the students gpa
			        setPhone)    // Used to set the students phone num

				   // Used to set the date of the object
				   ,gradDate(setDay,   // Used to set day graduation
						     setMonth, // Used to set month graduation
							 setYear)  // Used to set year of graduation
{
	asScore = setScore;
	java    = setJava;
}


// DECONSTRUCTOR
Csoc::~Csoc()
{
}

/* MUTATORS */

/**************************************************************************
 * METHOD ChangeScore
 * - This method changes the cs1c students score.
 * -> Return - nothing
 *************************************************************************/
void Csoc::ChangeScore(int newScore)
{
	asScore = newScore;
}

/**************************************************************************
 * METHOD ChangeJava
 * - This method changes whether or not the student has knowledge in java
 *   (will either be a yes or no).
 * -> Return - nothing
 *************************************************************************/
void Csoc::ChangeJava(string newString)
{
	java = newString;
}

/**************************************************************************
 * METHOD ChangeDate
 * - This method changes the cs1c students graduation date.
 * -> Return - nothing
 *************************************************************************/
void Csoc::ChangeDate(int newDay, int newMonth, int newYear)
{
	gradDate.ChangeDate(newDay, newMonth, newYear);
}

/* ACCESSORS */

/**************************************************************************
 * METHOD PrintColumns
 * - This method prints the top of the column with titles for PrintStudent
 * -> Return - A string
 *************************************************************************/
string Csoc::PrintColumns() const
{
	const int SIZE = 16; // spacing sizes
	ostringstream temp;  // temporary string variable

	// Sets the names of each column
	temp << left << setw(SIZE) << "Name"   << setw(SIZE) << "Student's Id"
		         << setw(SIZE) << "Phone"  << setw(4)    << "Age"
		         << setw(7)    << "Gender" << setw(SIZE) << "Class Standing"
		         << setw(7)    << "GPA"    << setw(17) << "Assignment"
				 " Score"
				 << setw(SIZE) << "Java Knowledge"
				 << setw(SIZE) << "Graduation Date" << endl;

	// Sets the lines under each name
	temp << right << setfill('-') << setw(SIZE) << ' ' << setw(SIZE) << ' '
			                      << setw(SIZE) << ' ' << setw(4)    << ' '
								  << setw(7)    << ' ' << setw(SIZE) << ' '
								  << setw(7)    << ' ' << setw(17)   << ' '
								  << setw(SIZE) << ' ' << setw(SIZE) << ' '
				  << setfill(' ') << endl;

	return temp.str();
}

/**************************************************************************
 * METHOD PrintStudent
 * - This method prints the student with all of their info in a column
 * 	 format.
 * -> Return - A string
 *************************************************************************/
string Csoc::PrintStudent() const
{
	const int SIZE = 16; // spacing sizes
	ostringstream temp;  // temporary string variable

	temp << fixed << setprecision(2);

	// Outputs the students information
	temp << left << setw(SIZE) << Student::GetName()
	             << setw(SIZE) << Student::GetId()
		         << setw(SIZE) << Student::GetPhone()
	             << setw(4)    << Student::GetAge()
		         << setw(7)    << Student::GetGender()
	             << setw(SIZE) << Student::GetStanding()
		         << setw(7)    << Student::GetGpa()
				 << setw(17)   << asScore << setw(SIZE) << java
				 << setw(SIZE) << gradDate.ReturnDate() << endl << right;

	return temp.str();
}
