/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "Date.h"

// DEFAULT CONSTRUCTOR
Date::Date()
{
	day   = 0;
	month = 0;
	year  = 0;
}

// NON-DEFAULT CONSTRUCTOR
Date::Date(int setDay, int setMonth, int setYear)
{
	day   = setDay;
	month = setMonth;
	year  = setYear;
}

// DECONSTRUCTOR
Date::~Date()
{
}

/* MUTATORS */

/**************************************************************************
 * METHOD ChangeDate
 * - This method changes the day, month, and year of the date.
 * -> Return - nothing
 *************************************************************************/
void Date::ChangeDate(int setDay, int setMonth, int setYear)
{
	day   = setDay;
	month = setMonth;
	year  = setYear;
}

/**************************************************************************
 * METHOD ReturnDate
 * - This method returns the date in a date friendly format.
 * -> Return - string
 *************************************************************************/
string Date::ReturnDate() const
{
	ostringstream temp; // temporary string stream

	temp << month << '/' << day << '/' << year;

	return temp.str();
}
