/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/
#ifndef PREFERREDMEMBER_H_
#define PREFERREDMEMBER_H_

#include "Date.h"
#include "BasicMember.h"

class PreferredMember: public BasicMember
{

public:
	PreferredMember();
	//default constructor

	PreferredMember(string name, int id, string memberType,
			        string memberExpiration);
	//non default constructor

	void SetRebate(double);
	//sets the rebate

	float GetRebate();
	//gets the rebate

	virtual void PrintDues();
	// prints the dues of a preferred member


private:

	//variables that are specific to the preferred members
	 float rebate;        // rebate back
	 float preferredDues; // the dues of a preferred member
};

#endif /* PREFERREDMEMBER_H_ */
