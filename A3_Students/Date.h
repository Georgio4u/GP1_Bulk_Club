/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include <iostream>
#include <sstream>
using namespace std;

#ifndef DATE_H_
#define DATE_H_

class Date
{
public:
	// DEFAULT CONSTRUCTOR
	Date();

	// NON-DEFAULT CONSTRUCTOR
	Date(int setDay,   // Used to set the day
		 int setMonth, // Used to set the month
		 int setYear); // Used to set the year

	// DECONSTRUCTOR
	~Date();

	/******************
	 **** MUTATORS ****
	 ******************/

	// Used to change the date
	void ChangeDate(int setDay, int setMonth, int setYear);

	/*******************
	 **** ACCESSORS ****
	 *******************/

	// Used to return the full date as a string
	string ReturnDate() const;

private:
	int day;   // Used to store the day
	int month; // Used to store the month
	int year;  // Used to the year
};



#endif /* DATE_H_ */
