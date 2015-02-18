/*
 * Date.h
 *
 *  Created on: Feb 12, 2015
 *      Author: Austin
 */

#ifndef DATE_H_
#define DATE_H_

//#include "BasicMember.h"


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <typeinfo>
using namespace std;


class Date
{
public:

/*****************************************************
CONSTRUCTORS & DESTRUCTOR
*****************************************************/

	//date constructor
	Date();

	//date overloaded constructor
	Date (int month,int day,int year);

	//date deconstructor
	~Date();

/*****************************************************
MUTATORS
*****************************************************/

	// will set the date in the date object dclared in account
	void SetDate(int month,int day,int year);

	// will set a whole date object at once
	void SetDate(Date d);

	//splits a string to day, month and year
	void SetDate(string date);

/******************************************************
ACCESSORS
******************************************************/

	// will return all date information
	void GetDate(int &month,int &day,int &year)const;

	// will return the year
	int GetYear()const;

	//will returen the month
	int GetMonth()const;

	//will return the date
	int GetDay()const;

	// Displays in MM/DD/YYYY format
	void DisplayDate()const;

	//counts the months to find interests.
	int CountMonths(Date toDate);

private:
	int dateMonth; //IN - month from file
	int dateDay;   //IN - day from file
	int dateYear;  //IN - year from file
};


#endif /* DATE_H_ */
