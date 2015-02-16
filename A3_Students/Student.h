/************************************************
 * AUTHOR		  : Georgio Christodulou
 * Student ID	  : 360794
 * ASSIGNMENT #3  : Students
 * CLASS		  : CS1C
 * SECTION		  : TTh 3:00p - 4:20p
 * DUE DATE		  : 2/10/2015
 ***********************************************/

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Student
{
public:
	// DEFAULT CONSTRUCTOR
	Student();

	// NON-DEFAULT CONSTRUCTOR
	Student(string setName,     // Used to set the students name
			char setGender,     // Used to set the students gender
			int setAge,         // Used to set the student age
			int setId,          // Used to set the students id
			string setStanding, // Used to set the students class standing
			float setGpa,       // Used to set the students gpa
			string setPhone);   // Used to set the students phone number

	// DECONSTRUCTOR
	~Student();

	/******************
	 **** MUTATORS ****
	 ******************/

	// Changes the students name
	void ChangeName(string newName);

	// Changes the student age
	void ChangeAge(int newAge);

	// Changes the students id number
	void ChangeId(int newiD);

	// Changes the student class standing (freshman, sophomore, etc)
	void ChangeStanding(string newStanding);

	// Changes the student grade point average
	void ChangeGpa(float newGpa);

	// Changes the students phone number
	void ChangePhone(string newPhone);

	/*******************
	 **** ACCESSORS ****
	 *******************/

	// Returns the students name
	string GetName() const;

	// Returns the students gender
	char GetGender() const;

	// Returns the students age
	int GetAge() const;

	// Returns the students id
	int GetId() const;

	// Returns the students class standing (freshman, sophomore, etc)
	string GetStanding() const;

	// Returns the students grade point average
	float GetGpa() const;

	// Returns the students phone number
	string GetPhone() const;

	// Returns the student type
	string StudentType() const;

	// Prints the top of the column for PrintStudents
	string PrintColumns() const;

	// Prints the Student with their information
	string PrintStudent() const;

private:
	string name;     // The students name
	char   gender;   // Stores the declared gender
	int    age;      // Stores the declared age
	int    id;       // The students id
	string standing; // Class standing - What year they are currently doing
	float  gpa;      // Students current grade point average
	string phone;    // The students phone number
};

#endif /* STUDENT_H_ */
