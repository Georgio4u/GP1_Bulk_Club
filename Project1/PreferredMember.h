
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


private:

	//variables that are specific to the preferred members
	 float rebate;
	 float preferredDues;
};

#endif /* PREFERREDMEMBER_H_ */
