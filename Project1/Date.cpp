/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/

#include "Date.h"

/************************************************************************
 CONSTRUCTORS & DESTRUCTOR
 ************************************************************************/
Date::Date()
{
	// initialized all values
	dateMonth = 0;
	dateDay = 0;
	dateYear = 0;
}

/*************************************************************************
 *
 * FUNCTION Date(constructor, overloaded)
 *________________________________________________________________________
 * This function will set all values one the program is compiled
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have instances declared in main
 *
 * Post-Conditions
 * 	This function will store date values in the date class from files
 ************************************************************************/
Date::Date(int month,  // IN - month from file
		int day,    // IN - day from file
		int year)   // IN - year from file
{

	// calls set year
	SetDate(month, day, year);
}

/*************************************************************************
 *
 * FUNCTION Date(deconstructor)
 *________________________________________________________________________
 * This function will destroy all values one the program is compiled
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have instances declared
 *
 * Post-Conditions
 * 	This function will delete date values in the date class from files
 ************************************************************************/
Date::~Date()
{

	// not used

}

/************************************************************************
 MUTATORS
 -------------------------------------------------------------------
 SetDate
 ************************************************************************/
// Sets the date given a month day and year
// Checks to see if the date is valid prior to settingthe date
/*************************************************************************/
void Date::SetDate(int month, // IN - month from file
		int day,   // IN - day from file
		int year)  // IN - year from file
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int currentYear;
	int currentMonth;
	int currentDay;
	int lastDayInMonth;
	tm * currentTime;

	// Used to find the current time
	// Find the current year based on the currentTime

	time_t now = time(0);
	currentTime = localtime(&now);
	currentYear = 2100; // 1900 + currentTime->tm_year;
	currentMonth = 1 + currentTime->tm_mon;
	currentDay = currentTime->tm_mday;

	// ERROR CHECK -The year, month & day
	// YEAR: The year must be between 1900 and the currentYear

	/***
	 if (year > currentYear || year < 1900)
	 {
	 cout << "\n*** Invalid Year(not changed) ***";
	 //cout << "Your year was " << year << " and the current year is "
	 //<< currentYear << endl;
	 }

	 // MONTH: The month must be between 0 and 12 or
	 // <= currentMonth for the currentYear

	 else if ((year != currentYear && (month > 12 || month < 0))
	 || (year == currentYear && month > currentMonth))
	 {
	 cout << "n*** InvalidMonth ***nn";
	 }

	 // DAY: The day must be <= the # of days in the month
	 // This also account for Leap Year

	 else
	 {
	 lastDayInMonth = daysInMonth[month - 1];
	 // LEAP YEAR Adjustment to lastDayInMonth
	 if (month == 2
	 && ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0))
	 {
	 lastDayInMonth++;
	 }
	 // Check if Day is valid

	 if ((day > lastDayInMonth || day < 0)
	 || (year == currentYear && month == currentMonth
	 && day > currentDay))
	 {
	 cout << "n*** Inavlid day ***nn";
	 }

	 else
	 {
	 ****/
	// Set the Date (if it is valid)
	dateMonth = month;
	dateDay = day;
	dateYear = year;

	// END-DAYCHECK

	// END-YEAR - MONTH If-else-if
}

/*************************************************************************
 *
 * FUNCTION SetDate
 *________________________________________________________________________
 * This function will set the date, (changed this function).
 *________________________________________________________________________
 * Pre-Conditions
 * 	calls setdate in this class, passes in a whole object
 *
 * Post-Conditions
 * 	This function will store values in a date object.
 ************************************************************************/
void Date::SetDate(Date d) // IN - date from files
{

	// sets the date by passing a whole object in
	SetDate(d.dateMonth, d.dateDay, d.dateYear);

}
/*************************************************************************
 *
 * FUNCTION SetDate
 *________________________________________________________________________
 * This function will set all values from a string
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have instances declared in main
 *
 * Post-Conditions
 * 	This function will store date values in the date class from files
 ************************************************************************/
void Date::SetDate(string date)
{
	bool dateWrong = false;

	int day, month, year;

	//converts string to 3 ints and then calls the other set method
	sscanf(date.c_str(), "%2d/%2d/%4d", &month, &day, &year);


	if (day < 0 || day > 32)
	{

		cout << "\nInvalid Day\n";
		dateWrong = true;

	}
	if (month < 0 || month > 12)
	{
		cout << "\nInvalid Month\n";
		dateWrong = true;
	}
	if (year < 1000 || year > 2100)
	{
		cout << "\nInvalid Year\n";
		dateWrong = true;
	}

	if (!dateWrong)
	{
		SetDate(month, day, year);
	}

}

/******************************************************
 ACCESSORS
 ------------------------------------------------
 GetDate
 GetYear
 GetMonth
 GetDay
 DisplayDate
 ******************************************************/
void Date::GetDate(int & month,      // IN - month from file
		int & day,        // IN - day from file
		int & year) const // IN - year from file
{
	//returns all values to location needed
	month = dateMonth;
	day = dateDay;
	year = dateYear;
}

/*************************************************************************
 *
 * FUNCTION GetYear
 *________________________________________________________________________
 * This function will get the year
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have some sort of date object
 *
 * Post-Conditions
 * 	This function will return thr date year
 ************************************************************************/
int Date::GetYear() const
{
	//return statement
	return dateYear;
}

/*************************************************************************
 *
 * FUNCTION GetMonth
 *________________________________________________________________________
 * This function will get the month
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have some sort of date object
 *
 * Post-Conditions
 * 	This function will return the month
 ************************************************************************/
int Date::GetMonth() const
{
	//return statement
	return dateMonth;
}

/*************************************************************************
 *
 * FUNCTION GetDay
 *________________________________________________________________________
 * This function will get the day
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have some sort of date object
 *
 * Post-Conditions
 * 	This function will return the day
 ************************************************************************/
int Date::GetDay() const
{
	//return statement
	return dateDay;
}

/*************************************************************************
 *
 * FUNCTION DisplayDate
 *________________________________________________________________________
 * This function will display the whole date
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have some sort of date object
 *
 * Post-Conditions
 * 	This function will dislpay the whole date with formatting
 ************************************************************************/
string Date::DisplayDate() const
{

	ostringstream buffer; // CALC - buffer used for spacing

	// Check if Day or Month are < 10 and add a leading 0 if necessary
	if (dateMonth < 10)
	{
		//out
		buffer << '0';
	}

	buffer << dateMonth << '/';
	//cout << buffer.str() << setw(12 - buffer.str().length());
	//buffer.str("");

	if (dateDay < 10)
	{
		//out
		buffer << '0';
	}

	//output date
	buffer << dateDay << '/' << dateYear;
	//cout << buffer.str() << setw(12 - buffer.str().length());
	//buffer.str("");

	return buffer.str();

}

/*************************************************************************
 *
 * FUNCTION CoutMonths(created by me)
 *________________________________________________________________________
 * This function will count the months between transactions and return a
 * count
 *________________________________________________________________________
 * Pre-Conditions
 * 	must have some sort of date object
 *
 * Post-Conditions
 * 	This function will return a count to find fees and amount of interest
 ************************************************************************/
int Date::CountMonths(Date toDate) // CALC - date of latest transaction
//        passed to compare with the
//        date last accessed.
{

	//comparing both dates
	int month1 = dateMonth;
	int year1 = dateYear;
	int month2 = toDate.GetMonth();
	int year2 = toDate.GetYear();
	int count;

	count = 0;

	// statement to increment count
	while (year1 < year2 || month1 < month2)
	{
		month1++;
		// will increase year of month is greater than 12
		if (month1 > 12)
		{
			year1++;
			month1 = 1;
		}
		//count increase
		count++;
	}

	//return count
	return count;
}

