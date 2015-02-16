/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/

#ifndef ERRORCHECK_H_
#define ERRORCHECK_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <limits>
#include <sstream>
using namespace std;

class ErrorCheck
{
public:
	// DEFAULT CONSTRUCTOR
	ErrorCheck();

	// NON-DEFUALT CONSTRUCTOR
	ErrorCheck(string setPrompt, // IN - Used to set the prompt
			   int setMin,       // IN - Used to set the min range
			   int setMax);      // IN - Used to set the max range

	// DECONSTRUCTOR
	~ErrorCheck();

	/******************
	 **** MUTATORS ****
	 ******************/

	// Used to change the prompt, min range, and max range
	void ChangeCheck(string newPrompt, int newMin, int newMax);

	/*******************
	 **** ACCESSORS ****
	 *******************/

	// Method the does the actual error checking
	int ValidateNumInput();

private:
	string prompt; // Used to store the message prompt
	int min;       // Used to determine the lowest number allowed
	int max;       // Used to determine the highest number allowed

	// Used only for the ValidateNumImput method to return an error message
	void ErrorOutput(int min, int max, int number);
};



#endif /* ERRORCHECK_H_ */
