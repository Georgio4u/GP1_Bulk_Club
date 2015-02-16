/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "Student.h"

// DEFAULT CONSTRUCTOR
Student::Student()
{
	name.clear();
	gender = 'N';
	age    = 0;
	id     = 0;
	standing.clear();
	gpa    = 0.0;
	phone.clear();
}

// NON-DEFAULT CONSTRUCTOR
Student::Student(string setName,     // Used to set the students name
		         char setGender,     // Used to set the students gender
		         int setAge,         // Used to set the student age
		         int setId,          // Used to set the students id
		         string setStanding, // Used to set the students class stan
		         float setGpa,       // Used to set the students gpa
		         string setPhone)    // Used to set the students phone num
{
	name     = setName;
	gender   = setGender;
	age      = setAge;
	id       = setId;
	standing = setStanding;
	gpa      = setGpa;
	phone    = setPhone;
}

// DECONSTRUCTOR
Student::~Student()
{
}

/* MUTATORS */

/**************************************************************************
 * METHOD ChangeName
 * - This method changes the students name.
 * -> Return - nothing
 *************************************************************************/
void Student::ChangeName(string newName)
{
	name = newName;
}

/**************************************************************************
 * METHOD ChangeAge
 * - This method takes in an integer to replace the name of the student.
 * -> Return - nothing
 *************************************************************************/
void Student::ChangeAge(int newAge)
{
	age = newAge;
}

/**************************************************************************
 * METHOD ChangeId
 * - This method changes the students id number.
 * -> Returns - nothing
 *************************************************************************/
void Student::ChangeId(int newId)
{
	id = newId;
}

/**************************************************************************
 * METHOD ChangeStanding
 * - This method takes in a string to replace the students class standing
 *   (freshman, sophomore, etc).
 * -> Returns - nothing
 *************************************************************************/
void Student::ChangeStanding(string newStanding)
{
	standing = newStanding;
}

/**************************************************************************
 * METHOD ChangeGpa
 * - This method takes in a float to change the students gpa.
 * -> Return - nothing
 *************************************************************************/
void Student::ChangeGpa(float newGpa)
{
	gpa = newGpa;
}

/**************************************************************************
 * METHOD ChangePhone
 * - This method takes in a string to change the students phone number
 * -> Return - nothing
 *************************************************************************/
void Student::ChangePhone(string newPhone)
{
	phone = newPhone;
}

/* ACCESSORS */

/**************************************************************************
 * METHOD GetName
 * - This method returns the students name.
 * -> Returns - string
 *************************************************************************/
string Student::GetName() const
{
	return name;
}

/**************************************************************************
 * METHOD GetGender
 * - This method returns the students gender.
 * -> Return - char
 *************************************************************************/
char Student::GetGender() const
{
	return gender;
}

/**************************************************************************
 * METHOD GetAge
 * - This method returns the students age.
 * -> Return - integer
 *************************************************************************/
int Student::GetAge() const
{
	return age;
}

/**************************************************************************
 * METHOD GetId
 * - This method returns the students id number.
 * -> Return - integer
 *************************************************************************/
int Student::GetId() const
{
	return id;
}

/**************************************************************************
 * METHOD GetStanding
 * - This method returns the student class standing (freshman, sophomore,
 *   etc).
 * -> Return - string
 *************************************************************************/
string Student::GetStanding() const
{
	return standing;
}

/**************************************************************************
 * METHOD GetGpa
 * - This method returns the students grade point average.
 * -> Return - float
 *************************************************************************/
float Student::GetGpa() const
{
	return gpa;
}

/**************************************************************************
 * METHOD GetPhone
 * - This method returns the students phone number.
 * -> Return - string
 *************************************************************************/
string Student::GetPhone() const
{
	return phone;
}

/**************************************************************************
 * METHOD StudentType
 * - This method returns the student type.
 * -> Returns string
 *************************************************************************/
string Student::StudentType() const
{
	return "Student";
}

/**************************************************************************
 * METHOD PrintColumns
 * - This method prints the top of the column with titles for PrintStudent
 * -> Return - A string
 *************************************************************************/
string Student::PrintColumns() const
{
	const int SIZE = 16; // spacing sizes
	ostringstream temp;  // temporary string variable

	// Sets the names of each column
	temp << left << setw(SIZE) << "Name"   << setw(SIZE) << "Student's Id"
		         << setw(SIZE) << "Phone"  << setw(4)    << "Age"
		         << setw(7)    << "Gender" << setw(SIZE) << "Class Standing"
		         << setw(7)    << "GPA"    << endl;

	// Sets the lines under each name
	temp << right << setfill('-') << setw(SIZE) << ' ' << setw(SIZE) << ' '
			                      << setw(SIZE) << ' ' << setw(4)    << ' '
								  << setw(7)    << ' ' << setw(SIZE) << ' '
								  << setw(7)    << ' '
				  << setfill(' ') << endl;

	return temp.str();
}

/**************************************************************************
 * METHOD PrintStudent
 * - This method prints the student with all of their info in a column
 * 	 format.
 * -> Return - A string
 *************************************************************************/
string Student::PrintStudent() const
{
	const int SIZE = 16; // spacing sizes
	ostringstream temp;  // temporary string variable

	temp << fixed << setprecision(2);

	// Outputs the students information
	temp << left << setw(SIZE) << name   << setw(SIZE) << id
		         << setw(SIZE) << phone  << setw(4)    << age
		         << setw(7)    << gender << setw(SIZE) << standing
		         << setw(7)    << gpa    << endl << right;

	return temp.str();
}
