/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Student.h"
#include "Date.h"
using namespace std;

#ifndef CS1CSTUDENT_H_
#define CS1CSTUDENT_H_

class Csoc: public Student
{
public:
	// DEFAULT CONSTRUCTOR
	Csoc();

	// NON-DEFUALT CONSTRUCTOR
	Csoc(string setName,     // Used to set the students name
		 char setGender,     // Used to set the students gender
		 int setAge,         // Used to set the student age
		 int setId,          // Used to set the students id
		 string setStanding, // Used to set the students class standing
		 float setGpa,       // Used to set the students gpa
		 string setPhone,    // Used to set the students phone number
         int setScore,       // Used to set the students assignment score
		 string setJava,     // Used to set if student knows java
		 int setDay,         // Used to set graduation day
		 int setMonth,       // Used to set graduation month
		 int setYear);       // Used to set graduation year


	// DECONSTRUCTOR
	~Csoc();

	/******************
	 **** MUTATORS ****
	 ******************/

	// Used to change the students assignment score
	void ChangeScore(int newScore);

	// Used to change the content for students java knowledge (yes or no)
	void ChangeJava(string newString);

	// Used to change students graduation date
	void ChangeDate(int newDay, int newMonth, int newYear);

	/*******************
	 **** ACCESSORS ****
	 *******************/

	// Prints the top of the column for PrintStudents
	string PrintColumns() const;

	// Prints the Student with their information
	string PrintStudent() const;

private:
	int asScore; // The students assignment score
	string java;    // Whether the student knows java or not
	Date gradDate;  // The students graduation date
};

#endif /* CS1CSTUDENT_H_ */
