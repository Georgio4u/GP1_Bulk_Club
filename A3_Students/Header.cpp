/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include "header.h"

// DEFUALT CONSTRIUCTOR
Header::Header()
{
	asName.clear();
	asType = 'A';
	asNum  = 0;
}

// NON-DEFAULT CONSTRUCTOR
Header::Header(string setName, // IN - Sets the assignment name
		       char setType,   // IN - Sets the program type
		       int setNum)     // IN - Sets the assignment number
{
	asName = setName;
	asType = setType;
	asNum  = setNum;
}

// DECONSTRUCTOR
Header::~Header()
{
}

/* ACCESSORS */

/**************************************************************************
 * METHOD ReturnHeader
 * - This method receives an assignment name, type and number then
 * 	 returns the appropriate header.
 * -> Returns - string
 *************************************************************************/
string Header::ReturnHeader() const
{
	/**********************************************************************
	 * CONSTANTS
	 * --------------------------------------------------------------------
	 * USED FOR SETTING BOX SIZE
	 * --------------------------------------------------------------------
	 * BOX_LENGTH : Defines the size of the class heading box
	 *********************************************************************/
	const int BOX_LENGTH = 41;

	ostringstream out;	//CALC - Defining the out string for header

	// OUTPUT - Prints class heading and makes assignment type changes
	//		based on input
	out << left;
	out << setfill('*');
	out << setw(BOX_LENGTH) << '*' << endl;
	out << setfill(' ');
	out << "* PROGRAMMED BY : Georgio Christodulou";
	out << "\n* " << setw(14) << "STUDENT ID" << ": 360794";
	out << "\n* " << setw(14) << "CLASS" << ": TTh - 3:00p - 4:20p";
	out << "\n* " ;
	if (toupper(asType) == 'L')
	{
		out << "LAB #" << setw(9);
	}
	else
	{
		out << "ASSIGNMENT #" << setw(2);
	}
	out << asNum << ": " << asName;
	out << setfill('*');
	out << endl << setw(BOX_LENGTH) << '*' << endl << endl;
	out << setfill(' ');
	out << right;

	return out.str();
}
