
/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/

#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_


#include "Date.h"

//base class of members
class BasicMember
{
public:
	BasicMember();
	//constructor(default)

	BasicMember(string name, int id, string memberType,
				string memberExpiration);
	//constructor(non default)

	void SettotalSpent(double);
	//setter for total spent

	string GetName();
	//getter for name

	int GetId();
	//getter for ID

	double GetTotalSpent();
	//getter for total spent

	string GetMemberType();
	//getter for member type

	int ReturnMonthFromDate();
	//returns the month from the date class to bulk club

	string ReturnDate();
	//reurns the date in string form again

	virtual void PrintDues();
	// prints the dues of members


private:

	//all the private data members for a regular membership:

	string name;             // name of member
	int memberId;            // ID of member
	string memberType;       // type of member
	Date memberExpiration;   // when the expiration of member is
	double totalSpent;       //how much the memebr spent
	 float basicDues;        //basic dues which is 55$

};

#endif /* BASICMEMBER_H_ */
