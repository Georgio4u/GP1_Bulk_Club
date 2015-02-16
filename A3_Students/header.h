/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Header
{
public:
	// DEFAULT CONSTRUCTOR
	Header();

	// NON-DEFAULT CONSTRUCTOR
	Header(string setName, // IN - Sets the assignment name
		   char setType,   // IN - Sets the assignment type (Lab or assign)
		   int setNum);    // IN - Sets the assignment number

	// DECONSTRUCTOR
	~Header();

	/*******************
	 **** ACCESSORS ****
	 *******************/

	// Returns the header as a string
	string ReturnHeader() const;

private:
	string asName; // Assignment name
	char asType;   // Assignment type (LAB or ASSIGNMENT)
	int asNum;     // Assignment number
};

#endif /* HEADER_H_ */
