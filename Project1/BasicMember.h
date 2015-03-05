

#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_


#include "Date.h"

//base class of members
class BasicMember
{
public:
	BasicMember();
	//constructor(default)

	BasicMember(string name, int id, string memberType,string memberExpiration);
	//constructor(non default)

	void SettotalSpent(double);
	//setter

	string GetName();
	//getter

	int GetId();
	//getter

	double GetTotalSpent();
	//getter

	string GetMemberType();
	//getter

	int ReturnMonthFromDate();

	virtual void PrintDues();

private:

	//all the private data members for a regular membership:

	string name;
	int memberId;
	string memberType;
	Date memberExpiration;
	double totalSpent;
	 float basicDues;

};

#endif /* BASICMEMBER_H_ */
